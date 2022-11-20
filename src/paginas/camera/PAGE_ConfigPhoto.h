#ifndef PAGE_CONFIGPHOTO_H
#define PAGE_CONFIGPHOTO_H
#include <Arduino.h>
#include "servidor/servidor.h"
#include "memoria/memoria.h"
#define FILE_PHOTO "/photo.jpg"

void vPhoto_config(void);
void vSend_photo_config(void);

extern boolean takeNewPhoto;
extern boolean CutePhoto;

const char PAGE_ConfigPhoto[] PROGMEM = R"=====(
<!--
Raferencia de crop Image with C
https://makexyz.fun/esp32-cam-cropping-images-on-device/
-->
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />
  <script src="microajax.js"></script> 
  <link rel="stylesheet" href="https://unpkg.com/jcrop/dist/jcrop.css">
  <script src="https://unpkg.com/jcrop@3.0.1/dist/jcrop.js"></script>  
</head>
<body>
    <div class="cabecalho2"><br>
        <a class="titulo_cabecalho" href="/">&nbsp;◄</a>&nbsp;&nbsp;
        <strong class="titulo_cabecalho">Configuracao de Rede</strong><br><br>
    </div>
    <hr style="margin-left: auto; margin-right: auto;"><div style="text-align: center;"><br>
    
  <div align="center">
    <table>
      <tr id="alig_center">
        <td><h2>ESP32-CAM Image Capture</h2></td>
      </tr>
      <tr id="alig_center">
        <td><button onclick="RotatePhoto();">ROTATE</button></td> <br>
      </tr>
      <tr>
        <td></td>
      </tr>
      <tr id="alig_center">
        <td><button onclick="capturePhoto()">CAPTURE PHOTO</button></td>
      </tr>
      <tr>
        <td border="1"><img src="/saved_photo" id="photo"></td>
      </tr>
      
      <form action="" method="post">
      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi11" id="roi11" size="3">
          y: <input type="text" name="roi12" id="roi12" size="3">
          w: <input type="text" name="roi13" id="roi13" size="3">
          h: <input type="text" name="roi14" id="roi14" size="3"> &nbsp;
          <button onclick="setROI1()">Pegar ROI 1</button>
          <button onclick="clearROI1()">Limpar ROI 1</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi21" id="roi21" size="3">
          y: <input type="text" name="roi22" id="roi22" size="3">
          w: <input type="text" name="roi23" id="roi23" size="3">
          h: <input type="text" name="roi24" id="roi24" size="3"> &nbsp;
          <button onclick="setROI2()">Pegar ROI 2</button>
          <button onclick="clearROI2()">Limpar ROI 2</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi31" id="roi31" size="3">
          y: <input type="text" name="roi32" id="roi32" size="3">
          w: <input type="text" name="roi33" id="roi33" size="3">
          h: <input type="text" name="roi34" id="roi34" size="3"> &nbsp;
          <button onclick="setROI3()">Pegar ROI 3</button>
          <button onclick="clearROI3()">Limpar ROI 3</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi41" id="roi41" size="3">
          y: <input type="text" name="roi42" id="roi42" size="3">
          w: <input type="text" name="roi43" id="roi43" size="3">
          h: <input type="text" name="roi44" id="roi44" size="3"> &nbsp;
          <button onclick="setROI4()">Pegar ROI 4</button>
          <button onclick="clearROI4()">Limpar ROI 4</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi51" id="roi51" size="3">
          y: <input type="text" name="roi52" id="roi52" size="3">
          w: <input type="text" name="roi53" id="roi53" size="3">
          h: <input type="text" name="roi54" id="roi54" size="3"> &nbsp;
          <button onclick="setROI5()">Pegar ROI 5</button>
          <button onclick="clearROI5()">Limpar ROI 5</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi61" id="roi61" size="3">
          y: <input type="text" name="roi62" id="roi62" size="3">
          w: <input type="text" name="roi63" id="roi63" size="3">
          h: <input type="text" name="roi64" id="roi64" size="3"> &nbsp;
          <button onclick="setROI6()">Pegar ROI 6</button>
          <button onclick="clearROI6()">Limpar ROI 6</button>
        </td>
      </tr>

      <tr id="alig_center">
        <td>
          <br>
          x: <input type="text" name="roi71" id="roi71" size="3">
          y: <input type="text" name="roi72" id="roi72" size="3">
          w: <input type="text" name="roi73" id="roi73" size="3">
          h: <input type="text" name="roi74" id="roi74" size="3"> &nbsp;
          <button onclick="setROI7()">Pegar ROI 7</button>
          <button onclick="clearROI7()">Limpar ROI 7</button>
        </td>
      </tr>
      <tr>
        <td>&nbsp;</td>
      </tr>
      <tr>
        <td align="right"><button onclick="Cute()">Salvar Imagens</button></td>
      </tr>
    </form>
       <tr>
        <td align="right"><button onclick="getValuesMemory()">Pegar Valores da Memoria</button></td>
      </tr>
      <tr>
        <td align="right"><button onclick="Corte()">Cortar Imagens</button></td>
      </tr>
      <tr id="alig_center">
        <td><h5> @2022 Jean de Souza - LaIoT Unifei </h5></td>
      </tr>
    </table>
  </div>
</body>

<form id="takepicture" method="post">
  <input id="takepicture" name="takepicture" type="hidden" value="1">
</form>

<form id="cutepicture" method="post">
  <input id="cutepicture" name="cutepicture" type="hidden" value="1">
</form>

<script language="JavaScript">

  function getValuesMemory()
  {
    var setVal = setValues("/admin/fotos");
    console.log(setVal);
  }

  function capturePhoto()
  {
      document.getElementById("takepicture").submit();
  }

  function Corte()
  {
    document.getElementById("cutepicture").submit();
  }

  var stage = Jcrop.attach('photo');
  var vet_rois1 = ["roi11", "roi12", "roi13", "roi14"];
  var vet_rois2 = ["roi21", "roi22", "roi23", "roi24"];
  var vet_rois3 = ["roi31", "roi32", "roi33", "roi34"];
  var vet_rois4 = ["roi41", "roi42", "roi43", "roi44"];
  var vet_rois5 = ["roi51", "roi52", "roi53", "roi54"];
  var vet_rois6 = ["roi61", "roi62", "roi63", "roi64"];
  var vet_rois7 = ["roi71", "roi72", "roi73", "roi74"];
  var deg = 0;

function setROIS(vet_roi){
  var pzs = stage.active.pos;
  document.getElementById(vet_roi[0]).value = pzs.x;
  document.getElementById(vet_roi[1]).value = pzs.y;
  document.getElementById(vet_roi[2]).value = pzs.w;
  document.getElementById(vet_roi[3]).value = pzs.h;
  location.reload();
  return pzs;
}

function clear(vet_roi_clear){
  for(var i = 0; i < vet_roi_clear.length; i++){
    document.getElementById(vet_roi_clear[i]).value = "";
  }
  location.reload();
}

// Coloca os dados dos ROI's
function setROI1(){
  setROIS(vet_rois1);
}
function setROI2(){
  setROIS(vet_rois2);
}
function setROI3(){
  setROIS(vet_rois3);
}
function setROI4(){
  setROIS(vet_rois4);
}
function setROI5(){
  setROIS(vet_rois5);
}
function setROI6(){
  setROIS(vet_rois6);
}
function setROI7(){
  setROIS(vet_rois7);
}

// Limpar os ROI's
function clearROI1(){
  clear(vet_rois1);
}
function clearROI2(){
  clear(vet_rois2);
}
function clearROI3(){
  clear(vet_rois3);
}
function clearROI4(){
  clear(vet_rois4);
}
function clearROI5(){
  clear(vet_rois5);
}
function clearROI6(){
  clear(vet_rois6);
}
function clearROI7(){
  clear(vet_rois7);
}
function Cute(){
  ImageCropCanvas(vet_rois1);
}

function isOdd(n) { return Math.abs(n % 2) == 1; }
function RotatePhoto()
{
  var rotate = document.getElementById("photo");
  deg += 30;
  if(isOdd(deg/90)){ document.getElementById("photo").className = "vert"; }
    else{ document.getElementById("photo").className = "hori"; }
    rotate.style.transform = "rotate(" + deg + "deg)";
}


function ImageCropCanvas(vet_roi_cut){
  var imagem = new Image();
  imagem.src = document.getElementById("photo").src;
  var imageVet = [];
  for(var i = 0; i < vet_roi_cut.length; i++){
    imageVet[i] = document.getElementById(vet_roi_cut[i]).value;
  }
  console.log(imageVet);
  //drawImage(image, sx, sy, sWidth, sHeight, dx, dy, dWidth, dHeight);
}
</script>
)=====";

const char PAGE_WaitAndReloaded[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="5; URL=configPhoto.html">
Aguarde....Configurando e Reiniciando.
)=====";

#endif