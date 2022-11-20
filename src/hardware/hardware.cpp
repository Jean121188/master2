#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>
#include "hardware.h"

void vInicializaHardware(void)
{
    Serial.begin(115200);
    if(!LittleFS.begin()){
        Serial.print("LittleFS fail... \n");
        return;
    }
}

void vReiniciar(){
  ESP.restart();
}
