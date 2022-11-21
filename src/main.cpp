#include <Arduino.h>
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>

#include "hardware/hardware.h"
#include "memoria/memoria.h"
#include "Wifi/wifi.h"
#include "servidor/servidor.h"
#include "camera/camera.h"

void setup() {
  vInicializaHardware();
  vLerConfiguracao();
  vInicializaWIFI();
  vInicializaServidor();
  vInicialized_cam();
  Serial.print("Init finish \n");
}

void loop() {
  
  server.handleClient();

  if(takeNewPhoto){
    vCapturePhotoSaveSpiffs();
    takeNewPhoto = false;
  }

}