#ifndef CAMERA_H
#define CAMERA_H

#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>
#include "esp_camera.h"
#include "esp_timer.h"
#include "servidor/servidor.h"

extern boolean takeNewPhoto;
extern boolean CutePhoto;

void vInicialized_cam(void);
void vHandle_capture(void);
void vGetSpiffImg(String path, String TyPe);
bool bCheckPhoto( fs::FS &fs );
String sReadFile(fs::FS &fs, const char * path);
void vCrop_image(camera_fb_t *fb, unsigned short cropLeft, unsigned short cropRight, unsigned short cropTop, unsigned short cropBottom);
void vGet_actualityphoto(void);
void vCapturePhotoSaveSpiffs(void);

#endif