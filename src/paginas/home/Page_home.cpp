#include "Page_home.h"

void vFilldynamicdata(void)
{
    String values ="";
    server.send ( 200, "text/plain", values);
}
void vProcessHome(void)
{
    server.send( 200, "text/html", PAGE_Home);
}