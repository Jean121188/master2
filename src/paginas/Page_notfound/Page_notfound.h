#ifndef PAGE_NOTFOUND_H
#define PAGE_NOTFOUND_H
#include <Arduino.h>

void vProcessnotfound(void);

const char PAGE_NotFound[] PROGMEM = R"=====(
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1" />
<p class="cabecalho">
    <strong class="titulo_cabecalho">Medidor de Energia</strong>
</p><br><br><br>
    <strong> Pagina Não Encontrada </strong><br><br>
    <button type="submit" class="btn">
        <a style="color: white; font-size: 130%" href="/">Ir para o Início</a>
    </button>
    <br><br>
<div>
<a> 
</div>
<div class="footer">
    <p style="margin-top: -5% !important;">
    Firmware v0.65
    <br><br>
    <a style="color: #0B1E2C" href = "https://ietecnologia.com/" > ietecnologia.com</a>
    <br><br>
    </p>
</div>
<script>
window.onload = function (){load("style.css","css", function() { });}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}
</script>
)=====";

#endif