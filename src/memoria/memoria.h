#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdlib.h>
#include <Arduino.h>
#include <Preferences.h>
#include "nvs.h"
#include "nvs_flash.h"

typedef struct{
  boolean tem_dados;
  String wifi_ssid;
  String wifi_pwd;
  boolean wifi_dhcp;
  byte wifi_ip[4];
  byte wifi_msk[4];
  byte wifi_gtw[4];
  byte wifi_dns[4];
  int rois[27];
  String ntp_name;
  long ntp_time;
  long ntp_timezone;
}config_t;
extern config_t config;

void vWriteConfig(void);
void vLerConfiguracao(void);
void vReiniciar(void);
boolean bReadConfig(void);

#endif