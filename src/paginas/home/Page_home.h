#ifndef PAGE_HOME_H
#define PAGE_HOME_H
#include <Arduino.h>
#include "servidor/servidor.h"

void vFilldynamicdata(void);
void vProcessHome(void);

const char PAGE_Home[] PROGMEM = R"=====(
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1" />
<p class="cabecalho">
    <strong class="titulo_cabecalho">Medidor de Enrgia</strong>
</p><br><br><br>

<button type="submit" class="btn">
        <a style="color: white; font-size: 130%" href="/configPhoto.html">ACESSAR O SISTEMA</a>
    </button>
    <br><br>
<div>
<a> 
<br>
  <p style="font-size: 150%; margin-left:1%; color: #565656; 
      font-weight: bold; background-color: transparent; padding: 10px; text-align: center;">
      LABTEL - Laboratorio de Internet das Coisas Unifei <br>
      Medidor de Energia com Tecnologia de Processamento de Borda
  </p>
</a>
</div>
<div class="footer">
    <p style="margin-top: -5% !important;">
    Firmware v0.1
    <br><br>
    </p>
</div>
<script>
window.onload = function (){load("style.css","css", function() { });}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}
</script>
)=====";

#endif
