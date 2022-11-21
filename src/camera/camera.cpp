#include "camera.h"
#include "camera_index.h"

boolean takeNewPhoto = false;

void vInicialized_cam(void)
{
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  // config.pixel_format = PIXFORMAT_JPEG;
  // config.frame_size = FRAMESIZE_SVGA; //old FRAMESIZE_240X240; // FRAMESIZE_SVGA (800x600)

  config.pixel_format = PIXFORMAT_RGB565;
  config.frame_size = FRAMESIZE_SXGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK){
    Serial.printf("Camera init failed with error 0x%x", err);
    //resetModule();
  }
  sensor_t *s = esp_camera_sensor_get();
  s->set_vflip(s, 1);
}

void vGetSpiffImg(String path, String TyPe){ 
//  if(LittleFS.exists(path)){
if(SD_MMC.exists(path)){ 
    // File file = LittleFS.open(path, "r");
    File file = SD_MMC.open(path, "r");
    server.streamFile(file, TyPe);
    file.close();
  }
}

bool bCheckPhoto( fs::FS &fs ) {
  File f_pic = fs.open( FILE_PHOTO );
  unsigned int pic_sz = f_pic.size();
  return ( pic_sz > 100 );
}

String sReadFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
    }

    Serial.println("- read from file:");
    int count = 0;
    String msg = "";
    while(file.available()){
        msg += file.read();
        msg += " ";
        count++;
        if(count > 800){
          msg += "\n";
          count = 0;
        }
    }
    file.close();
    return msg;
}

void vCrop_image(camera_fb_t *fb, unsigned short cropLeft, unsigned short cropRight, unsigned short cropTop, unsigned short cropBottom)
{
    Serial.print("Entrei no crop_image \n");
    unsigned int maxTopIndex = cropTop * fb->width * 2;
    unsigned int minBottomIndex = ((fb->width*fb->height) - (cropBottom * fb->width)) * 2;
    unsigned short maxX = fb->width - cropRight; // In pixels
    unsigned short newWidth = fb->width - cropLeft - cropRight;
    unsigned short newHeight = fb->height - cropTop - cropBottom;
    size_t newJpgSize = newWidth * newHeight *2;
    unsigned int writeIndex = 0;

    Serial.print("Setei as variaveis do CROP \n");
    // Loop over all bytes
    for(int i = 0; i < fb->len; i+=2){
        // Calculate current X, Y pixel position
        int x = (i/2) % fb->width;

        // Crop from the top
        if(i < maxTopIndex){ continue; }

        // Crop from the bottom
        if(i > minBottomIndex){ continue; }

        // Crop from the left
        if(x <= cropLeft){ continue; }

        // Crop from the right
        if(x > maxX){ continue; }

        // If we get here, keep the pixels
        fb->buf[writeIndex++] = fb->buf[i];
        fb->buf[writeIndex++] = fb->buf[i+1];
    }
    Serial.print("Sai do loop \n");
    // Set the new dimensions of the framebuffer for further use.
    fb->width = newWidth;
    fb->height = newHeight;
    fb->len = newJpgSize;
    Serial.print("FIM da Função \n");
}

void vGet_actualityphoto(){
  // String values = (String)sReadFile(LittleFS, FILE_PHOTO);
  String values = (String)sReadFile(SD_MMC, FILE_PHOTO);
  server.send ( 200, "text/plain", values);
}

void vHandle_capture() {
  takeNewPhoto = true;
  Serial.println("Capturing Image");
  server.send(200, "text/plain", "Taking Photo"); 
}

bool bCuteImage(const char* ROI){
   camera_fb_t *fb = NULL;
   fb = esp_camera_fb_get();
   if (!fb) {
      Serial.println("Camera capture failed");
      return false;
    }else{
      Serial.println("Camera capture!");
    }
  // ROI1
  // crop_image(camera_fb_t *fb, unsigned short cropLeft, unsigned short cropRight, unsigned short cropTop, unsigned short cropBottom)
  vCrop_image(fb, (unsigned short)config.rois[0], (unsigned short)config.rois[0], (unsigned short)config.rois[0], (unsigned short)config.rois[0]);
  // File file = LittleFS.open(ROI, FILE_WRITE);
  File file = SD_MMC.open(ROI, FILE_WRITE);
  if (!file) {
      Serial.println("Failed to open file in writing mode");
  }else {
    Serial.print("Abri o arquivo inciando a gravacao...");
    file.write(fb->buf, fb->len); // payload (image), payload length
    Serial.print("The picture has been saved in ");
    Serial.print(ROI);
    Serial.print(" - Size: ");
    Serial.print(file.size());
    Serial.println(" bytes");
  }
  file.close();
  esp_camera_fb_return(fb);
  // return bCheckPhoto(LittleFS);
  return bCheckPhoto(SD_MMC);
}

void vCapturePhotoSaveSpiffs(void)
{
  camera_fb_t *fb = NULL;
  bool ok = 0;
  do{
    fb = esp_camera_fb_get(); // função que tira a foto
    if (!fb) {
      Serial.println("Camera capture failed");
      return;
    }
    
    fs::FS &fs = SD_MMC;
    File file = fs.open(FILE_PHOTO, FILE_WRITE);
    
    //File file = LittleFS.open(FILE_PHOTO, FILE_WRITE);
    if (!file) {
      Serial.println("Failed to open file in writing mode");
    }else {
      file.write(fb->buf, fb->len); // payload (image), payload length
      Serial.printf("The picture has been saved in %s - Size: %i bytes \n", FILE_PHOTO, file.size());
    }
    file.close();
    esp_camera_fb_return(fb);
    // ok = bCheckPhoto(LittleFS);
    ok = bCheckPhoto(SD_MMC);
  }while(!ok);

}