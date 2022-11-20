#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <Arduino.h>
#include <WebServer.h>

#include "paginas/Page_microajax.h"
#include "paginas/Page_style.h"
#include "paginas/home/Page_home.h"
#include "paginas/camera/PAGE_ConfigPhoto.h"
#include "paginas/Page_notfound/Page_notfound.h"
#include "camera/camera.h"

#define ROI1 "/roi1.jpg"

extern WebServer server;

void vInicializaServidor(void);
void vProcessmicroajax(void);
void vProcessstyle(void);

#endif