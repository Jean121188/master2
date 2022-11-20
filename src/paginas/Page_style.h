#ifndef PAGE_STYLECSS_H
#define PAGE_STYLECSS_H
#include <Arduino.h>

const char Page_Style_css[] PROGMEM = R"=====(
html { color: #000000; font-family: avenir, helvetica, arial, sans-serif;  letter-spacing: 0.15em; height: 100%;}
body {text-align: center; color: #000000; font-family: avenir, helvetica, arial, sans-serif;  letter-spacing: 0.15em;background-repeat: no-repeat; /*background-image: linear-gradient(white 10%, #0074D9)*/}
hr {    background-color: #eee;    border: 0 none;   color: #eee;    height: 1px; }

.btn{background-color: #0074D9; border-radius: 0.3em;border-style: solid;border-width: 1px;color: white;display: inline-block;font-family: avenir, helvetica, arial, sans-serif;letter-spacing: 0.15em;padding: 10px; width: 225px; font-size: 75%; font-weight: bold}

@media screen and (min-width: 32em) {.btn--full {max-width: 16em !important;}}
a:link{text-decoration:none;}
*{margin:0;}
.footer {position:absolute;bottom:0;width:100%;color: #0074D9;font-weight: bold;font-size: 75%;font-family: "helvetica";}
.c2 {width: 100%;display: flex;flex-direction: row;justify-content: center;align-items: center;}
.c3 {width: 30%;}
.c1 {width: 100%;position: relative;margin-left:0%;}
.nova{width:100%;float: right;}
.container-center{position:relative;top: 20px;text-align: center;left: 40%;right: 0px;}
#td{padding: 20px; padding-left: 50px; padding-right: 50px;}
#user input{border-radius: 5px; padding: 3px;}
.container-general{text-align: center;}
.cabecalho{background-color: #0074D9;font-size: 110%; color: white; padding: 15px; text-align: center;}
.cabecalho2{background-color: #0074D9; text-align: left;}
.titulo_cabecalho{color: white; text-align: center}
.titulo_grafico{background-color: #0074D9; padding: 5px; color: white; border-radius: 5px}
#alig_center{text-align: center;}
)=====";
#endif