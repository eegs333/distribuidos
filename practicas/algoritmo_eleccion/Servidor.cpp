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
#include <iostream>

using namespace std;
int puerto = 7200;

void screen(char * argv[])
{
	int ysize = 300;
	int xsize = 1300;
	int x = 0 ;
	int y = 25;
	int factor;
	int ascii;
	char c;
	gfx_open(xsize,ysize,"Mensajes");
	gfx_color(0,200,100);
	//Generar IP
	char* ip = argv[3];
	for(char* it = ip; *it; ++it) {
		factor = 7;
		y = 25;
		ascii = int(*it);
		if(ascii == 46){
			factor = 1;
			y = 100;
		}
		cout << *it << " = " << ascii << endl;
		x += 70;
		gfx_display_ascii(x, y , factor, ascii);
	}
	//Generar mensaje
	x = 0;
	char* str = argv[2];
	for(char* its = str; *its; ++its) {
		factor = 3;

		y = 150;
		ascii = int(*its);
		x += 70;
		gfx_display_ascii(x, y , factor, ascii);
	}


	while(1) {
		c = gfx_wait();
		if(c=='q') break;
	}
}

void grandulon(char * IP[]){
	char msj = "ELECCION";
	for(int i = 0; i > sizeof(IP); i++){
		cout << IP[i] << endl;
		PaqueteDatagrama paqueteEnviado(msj,sizeof(msj),IP[i],puerto);
		if(paqueteRecibido.obtieneDatos() == "OK"){
			cout << "Coordinador: " << IP[i] <<  endl;
		}
	}
}
int main(int argc, char * argv[]) {
		char out [30];
		char in [30];
		char *IP[15];
		for(int i = 1; i < argc; i++){
				IP[i] = argv[i];
				cout << IP[i] << endl;
		}
    SocketDatagrama socket(puerto);
    printf("Esperando mensajes...\n");
		//screen(argv);
    while (1) {
			PaqueteDatagrama paqueteRecibido(sizeof(out));
				if(paqueteRecibido.obtieneDatos()){

				}
	    PaqueteDatagrama paqueteEnviado(out,sizeof(out),paqueteRecibido.obtieneDireccion(),puerto);
			socket.recibe(paqueteRecibido);
      paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
      socket.envia(paqueteEnviado);
    }
}
