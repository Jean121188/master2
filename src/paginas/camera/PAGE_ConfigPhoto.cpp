#include "PAGE_ConfigPhoto.h"

boolean CutePhoto = false;

void vPhoto_config(void)
{
    if (server.args() > 0 )
  {
    String temp = "";
    for ( uint8_t i = 0; i < server.args(); i++ )
    {
      if (server.argName(i) == "roi11") if (server.arg(i)) config.rois[0] = server.arg(i).toInt();
      if (server.argName(i) == "roi12") if (server.arg(i)) config.rois[1] = server.arg(i).toInt();
      if (server.argName(i) == "roi13") if (server.arg(i)) config.rois[2] = server.arg(i).toInt();
      if (server.argName(i) == "roi14") if (server.arg(i)) config.rois[3] = server.arg(i).toInt();

      if (server.argName(i) == "roi21") if (server.arg(i)) config.rois[4] = server.arg(i).toInt();
      if (server.argName(i) == "roi22") if (server.arg(i)) config.rois[5] = server.arg(i).toInt();
      if (server.argName(i) == "roi23") if (server.arg(i)) config.rois[6] = server.arg(i).toInt();
      if (server.argName(i) == "roi24") if (server.arg(i)) config.rois[7] = server.arg(i).toInt();

      if (server.argName(i) == "roi31") if (server.arg(i)) config.rois[8] = server.arg(i).toInt();
      if (server.argName(i) == "roi32") if (server.arg(i)) config.rois[9] = server.arg(i).toInt();
      if (server.argName(i) == "roi33") if (server.arg(i)) config.rois[10] = server.arg(i).toInt();
      if (server.argName(i) == "roi34") if (server.arg(i)) config.rois[11] = server.arg(i).toInt();

      if (server.argName(i) == "roi41") if (server.arg(i)) config.rois[12] = server.arg(i).toInt();
      if (server.argName(i) == "roi42") if (server.arg(i)) config.rois[13] = server.arg(i).toInt();
      if (server.argName(i) == "roi43") if (server.arg(i)) config.rois[14] = server.arg(i).toInt();
      if (server.argName(i) == "roi44") if (server.arg(i)) config.rois[15] = server.arg(i).toInt();

      if (server.argName(i) == "roi51") if (server.arg(i)) config.rois[16] = server.arg(i).toInt();
      if (server.argName(i) == "roi52") if (server.arg(i)) config.rois[17] = server.arg(i).toInt();
      if (server.argName(i) == "roi53") if (server.arg(i)) config.rois[18] = server.arg(i).toInt();
      if (server.argName(i) == "roi54") if (server.arg(i)) config.rois[19] = server.arg(i).toInt();

      if (server.argName(i) == "roi61") if (server.arg(i)) config.rois[20] = server.arg(i).toInt();
      if (server.argName(i) == "roi62") if (server.arg(i)) config.rois[21] = server.arg(i).toInt();
      if (server.argName(i) == "roi63") if (server.arg(i)) config.rois[22] = server.arg(i).toInt();
      if (server.argName(i) == "roi64") if (server.arg(i)) config.rois[23] = server.arg(i).toInt();

      if (server.argName(i) == "roi71") if (server.arg(i)) config.rois[24] = server.arg(i).toInt();
      if (server.argName(i) == "roi72") if (server.arg(i)) config.rois[25] = server.arg(i).toInt();
      if (server.argName(i) == "roi73") if (server.arg(i)) config.rois[26] = server.arg(i).toInt();
      if (server.argName(i) == "roi74") if (server.arg(i)) config.rois[27] = server.arg(i).toInt();
      
      if (server.argName (i) == "takepicture"){
        Serial.println("Entrei no Take a Picture...");
        takeNewPhoto = true;
      }
      
      if (server.argName (i) == "cutepicture"){
        Serial.println("Entrei no cutepicture...");
        server.send ( 200, "text/html", PAGE_WaitAndReloaded);
        CutePhoto = true;
      }
      //
    }
    vWriteConfig();  // Garava os parametros no módulo
    // server.send ( 200, "text/html", PAGE_WaitAndReloaded);
    // AdminTimeOutCounter=0;
  }
  else
  {
    server.send ( 200, "text/html", PAGE_ConfigPhoto );
  }
}
void vSend_photo_config(void)
{
    String values ="";
    values += "roi11|" + (String) config.rois[0] + "|input\n";
    values += "roi12|" + (String) config.rois[1] + "|input\n";
    values += "roi13|" + (String) config.rois[2] + "|input\n";
    values += "roi14|" + (String) config.rois[3] + "|input\n";

    values += "roi21|" + (String) config.rois[4] + "|input\n";
    values += "roi22|" + (String) config.rois[5] + "|input\n";
    values += "roi23|" + (String) config.rois[6] + "|input\n";
    values += "roi24|" + (String) config.rois[7] + "|input\n";

    values += "roi31|" + (String) config.rois[8] + "|input\n";
    values += "roi32|" + (String) config.rois[9] + "|input\n";
    values += "roi33|" + (String) config.rois[10] + "|input\n";
    values += "roi34|" + (String) config.rois[11] + "|input\n";

    values += "roi41|" + (String) config.rois[12] + "|input\n";
    values += "roi42|" + (String) config.rois[13] + "|input\n";
    values += "roi43|" + (String) config.rois[14] + "|input\n";
    values += "roi44|" + (String) config.rois[15] + "|input\n";

    values += "roi51|" + (String) config.rois[16] + "|input\n";
    values += "roi52|" + (String) config.rois[17] + "|input\n";
    values += "roi53|" + (String) config.rois[18] + "|input\n";
    values += "roi54|" + (String) config.rois[19] + "|input\n";

    values += "roi61|" + (String) config.rois[20] + "|input\n";
    values += "roi62|" + (String) config.rois[21] + "|input\n";
    values += "roi63|" + (String) config.rois[22] + "|input\n";
    values += "roi64|" + (String) config.rois[23] + "|input\n";

    values += "roi71|" + (String) config.rois[24] + "|input\n";
    values += "roi72|" + (String) config.rois[25] + "|input\n";
    values += "roi73|" + (String) config.rois[26] + "|input\n";
    values += "roi74|" + (String) config.rois[27] + "|input\n";
  
    server.send ( 200, "text/plain", values);
}