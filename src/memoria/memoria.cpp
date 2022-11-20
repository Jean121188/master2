#include <Arduino.h>
#include "memoria.h"

Preferences preferences;
config_t config;

void vWriteConfig(void)
{
  Serial.println(F("Escrevendo Configuracao"));
  preferences.begin("config", false);
  preferences.putBool("tem_dados", config.tem_dados);
  preferences.putString("wifi_ssid", config.wifi_ssid);
  preferences.putString("wifi_pwd", config.wifi_pwd);
  preferences.putBool("wifi_dhcp", config.wifi_dhcp); 
  preferences.putBytes("wifi_ip",config.wifi_ip,4);
  preferences.putBytes("wifi_msk",config.wifi_msk,4);
  preferences.putBytes("wifi_gtw",config.wifi_gtw,4);
  preferences.putBytes("wifi_dns",config.wifi_dns,4);

  preferences.putString("ntp_name", config.ntp_name);
  preferences.putLong("ntp_time",config.ntp_time);
  preferences.putLong("ntp_timezone",config.ntp_timezone);

  preferences.putInt("roi11", config.rois[0]);
  preferences.putInt("roi12", config.rois[1]);
  preferences.putInt("roi13", config.rois[2]);
  preferences.putInt("roi14", config.rois[3]);
  preferences.putInt("roi21", config.rois[4]);
  preferences.putInt("roi22", config.rois[5]);
  preferences.putInt("roi23", config.rois[6]);
  preferences.putInt("roi24", config.rois[7]);
  preferences.putInt("roi31", config.rois[8]);
  preferences.putInt("roi32", config.rois[9]);
  preferences.putInt("roi33", config.rois[10]);
  preferences.putInt("roi34", config.rois[11]);
  preferences.putInt("roi41", config.rois[12]);
  preferences.putInt("roi42", config.rois[13]);
  preferences.putInt("roi43", config.rois[14]);
  preferences.putInt("roi44", config.rois[15]);
  preferences.putInt("roi51", config.rois[16]);
  preferences.putInt("roi52", config.rois[17]);
  preferences.putInt("roi53", config.rois[18]);
  preferences.putInt("roi54", config.rois[19]);
  preferences.putInt("roi61", config.rois[20]);
  preferences.putInt("roi62", config.rois[21]);
  preferences.putInt("roi63", config.rois[22]);
  preferences.putInt("roi64", config.rois[23]);
  preferences.putInt("roi71", config.rois[24]);
  preferences.putInt("roi72", config.rois[25]);
  preferences.putInt("roi73", config.rois[26]);
  preferences.putInt("roi74", config.rois[27]);

  preferences.end();
  Serial.println(F("Terminei o preferences..."));
}

boolean bReadConfig(void)
{
  Serial.println(F("Read Config"));
  preferences.begin("config", false);                         //Namespace: config; Mode: false (R-W)
  config.tem_dados = preferences.getBool("tem_dados", false); //
  if(config.tem_dados)
  {
    config.wifi_ssid = preferences.getString("wifi_ssid", "");
    config.wifi_pwd = preferences.getString("wifi_pwd", "");
    config.wifi_dhcp = preferences.getBool("wifi_dhcp", true); 
    preferences.getBytes("wifi_ip",config.wifi_ip,4);
    preferences.getBytes("wifi_msk",config.wifi_msk,4);
    preferences.getBytes("wifi_gtw",config.wifi_gtw,4);
    preferences.getBytes("wifi_dns",config.wifi_dns,4);

    preferences.getInt("roi11", config.rois[0]);
    preferences.getInt("roi12", config.rois[1]);
    preferences.getInt("roi13", config.rois[2]);
    preferences.getInt("roi14", config.rois[3]);
    
    preferences.getInt("roi21", config.rois[4]);
    preferences.getInt("roi22", config.rois[5]);
    preferences.getInt("roi23", config.rois[6]);
    preferences.getInt("roi24", config.rois[7]);
    
    preferences.getInt("roi31", config.rois[8]);
    preferences.getInt("roi32", config.rois[9]);
    preferences.getInt("roi33", config.rois[10]);
    preferences.getInt("roi34", config.rois[11]);
    
    preferences.getInt("roi41", config.rois[12]);
    preferences.getInt("roi42", config.rois[13]);
    preferences.getInt("roi43", config.rois[14]);
    preferences.getInt("roi44", config.rois[15]);
    
    preferences.getInt("roi51", config.rois[16]);
    preferences.getInt("roi52", config.rois[17]);
    preferences.getInt("roi53", config.rois[18]);
    preferences.getInt("roi54", config.rois[19]);
    
    preferences.getInt("roi61", config.rois[20]);
    preferences.getInt("roi62", config.rois[21]);
    preferences.getInt("roi63", config.rois[22]);
    preferences.getInt("roi64", config.rois[23]);
    
    preferences.getInt("roi71", config.rois[24]);
    preferences.getInt("roi72", config.rois[25]);
    preferences.getInt("roi73", config.rois[26]);
    preferences.getInt("roi74", config.rois[27]);
    
    preferences.end();
    return true;
  }else{
    preferences.end();
    Serial.println(F("Configuracao nao encontrada!!!!"));
    return false;
  }
}

void vLerConfiguracao(void)
{
  if (!bReadConfig())
  {
    config.tem_dados = true;
    config.wifi_ssid = "Rep Uteiro";
    config.wifi_pwd = "naotemsenha";
    config.wifi_dhcp = true;

    // config.wifi_ip[0] = 192; config.wifi_ip[1] = 168; config.wifi_ip[2] = 1; config.wifi_ip[3] = 100;
    // config.wifi_msk[0] = 255; config.wifi_msk[1] = 255; config.wifi_msk[2] = 255; config.wifi_msk[3] = 0;
    // config.wifi_gtw[0] = 192; config.wifi_gtw[1] = 168; config.wifi_gtw[2] = 1; config.wifi_gtw[3] = 1;
    // config.wifi_dns[0] = 192; config.wifi_dns[1] = 168; config.wifi_dns[2] = 1; config.wifi_dns[3] = 1;

    // config.ntp_name = "0.br.pool.ntp.org";
    // config.ntp_time = 1;
    // config.ntp_timezone = -30;

    config.rois[1] = 1; config.rois[2] = 1; config.rois[3] = 1; config.rois[4] = 1; config.rois[5] = 1;
    config.rois[6] = 1; config.rois[7] = 1; config.rois[8] = 1; config.rois[9] = 1; config.rois[10] = 1;
    config.rois[11] = 1; config.rois[12] = 1; config.rois[13] = 1; config.rois[14] = 1; config.rois[15] = 1;
    config.rois[16] = 1; config.rois[17] = 1; config.rois[18] = 1; config.rois[19] = 1; config.rois[20] = 1;
    config.rois[21] = 1; config.rois[22] = 1; config.rois[23] = 1; config.rois[24] = 1; config.rois[25] = 1;
    config.rois[26] = 1; config.rois[27] = 1;
    
    vWriteConfig(); // default gravado na EEPROM
    Serial.println(F("Configuracao Feita"));
  }
}