#include "wifi.h"

void vInicializaWIFI(void)
{
    byte mac[6];
    WiFi.macAddress(mac);
    WiFi.mode(WIFI_STA);
    vConfigureWifi();
}

void vConfigureWifi()
{
    WiFi.disconnect();
    Serial.print("Configurando Wifi");
    WiFi.begin(config.wifi_ssid.c_str(), config.wifi_pwd.c_str());

    while (WiFi.status() != WL_CONNECTED)
    {
        if(WiFi.status() == WL_NO_SSID_AVAIL){Serial.print("SEM SSID");break;}
        if(WiFi.status() == WL_CONNECT_FAILED){Serial.print("Falhou o Wifi");break;}
        Serial.print("#");
        delay(300);
    }

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}