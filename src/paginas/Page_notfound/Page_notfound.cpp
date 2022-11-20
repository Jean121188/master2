#include "Page_notfound.h"
#include "servidor/servidor.h"

void vProcessnotfound(void){
    server.send ( 400, "text/html", PAGE_NotFound );
}