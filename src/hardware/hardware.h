#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>
#include <FS.h>
// #include <LittleFS.h>
#include <SD_MMC.h>

#define RUN 16
#define NET 17
#define FORMAT_LITTLEFS_IF_FAILED true

void vInicializaHardware(void);
void vReiniciar(void);

#endif