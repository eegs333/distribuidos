#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "gfxModified.h"

int puerto = 7200;

void screen()
{
	int ysize = 300;
	int xsize = 300;
	int x = 100;
	int y = 25;
	int factor = 20;
	int ascii = 69;
	char c;

	gfx_open(xsize,ysize,"Graphics Program");
	gfx_color(0,200,100);
	gfx_display_ascii(x, y , factor, ascii);
	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

}



int main(void) {
	screen();
  /*  SocketDatagrama socket(puerto);
    PaqueteDatagrama paqueteRecibido(65536);
    PaqueteDatagrama paqueteEnviado(out,1,IP,puerto);
    printf("Esperando mensajes...\n");

    while (1) {
        socket.recibe(paqueteRecibido));
        paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
        socket.envia(paqueteEnviado);
    }*/
}
