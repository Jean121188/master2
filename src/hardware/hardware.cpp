#include "hardware.h"

uint8_t cardType;

void vInicializaHardware(void)
{
    Serial.begin(115200);
    
    // Little FS
    // if(!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)){
    //     Serial.println("LittleFS Mount Failed");
    //     return;
    // }

    // SD CARD
    if(!SD_MMC.begin()){
      Serial.print("NO SDCARD detect \n");
    }
    else{
      Serial.printf("SD CARD Mount, size: %i\n", SD_MMC.totalBytes());
    }

    cardType = SD_MMC.cardType();
    if(cardType == CARD_NONE){
      Serial.println("No SD Card attached");
    }
}

void vReiniciar(){
  ESP.restart();
}
