#include "servidor.h"

WebServer server(80);

void vInicializaServidor(void)
{
    server.on ("/microajax.js", vProcessmicroajax);
    server.on ("/style.css", vProcessstyle);
    server.on ("/", vProcessHome);
    server.on ("/configPhoto.html", vPhoto_config);
    server.on ("/saved_photo", []() {vGetSpiffImg(FILE_PHOTO,"image/jpg");}); 
    server.on ("/roi1_saved", []() {vGetSpiffImg(ROI1,"image/jpg");});

    server.on ("/admin/photo", vSend_photo_config);
    server.on ("/capture", vHandle_capture);
    server.on ("/admin/fotos", vSend_photo_config);
    server.on ("/admin/actualityphoto", vGet_actualityphoto);

    server.onNotFound(vProcessnotfound);
    server.begin();
}

void vProcessmicroajax()
{
  server.send(200, "text/plain", Page_microajax);
}

void vProcessstyle()
{
  server.send ( 200, "text/plain", Page_Style_css );  
}