#include <stdio.h>
#include <math.h>
#include "gfxModified.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600
#define pi 3.1416
int puerto = 7200;

void pintaGrafica(int x, int y);
void borraGrafica(int x, int y);



int main(void)
{
	char* coord;

    int x=0,y=0;

    int n=1;
    srand (time(NULL));
    char* res;
    //Servidor
    char out[1024] = "V";
    int f,cont=0;
    gfx_open(ANCHURA, ALTURA, "Serie de Fourier"); 
    gfx_line( 0, 300, 800, 300 );
    gfx_line( 400, 0, 400, 600 );
    SocketDatagrama socket(puerto);
    PaqueteDatagrama paqueteEnviado(out,1,"10.100.65.74",puerto);
        printf("Esperando mensajes...\n");
    while (1) {
        PaqueteDatagrama paqueteRecibido(100);
        //printf("%d\n",socket.recibe(paqueteRecibido)); 
        socket.recibe(paqueteRecibido);
        char* s=paqueteRecibido.obtieneDatos();
        cout <<paqueteRecibido.obtieneDatos();
        res = strchr(paqueteRecibido.obtieneDatos(),',');
        if(res != NULL){
            coord = strtok(paqueteRecibido.obtieneDatos(),",");
            x=atoi(coord);
            coord = strtok(NULL,",");
            y=atoi(coord);
            coord = strtok(NULL,",");
            pintaGrafica(x,y);
        }else{
            coord = strtok(paqueteRecibido.obtieneDatos(),";");
            x=atoi(coord);
            coord = strtok(NULL,";");
            y=atoi(coord);
            coord = strtok(NULL,";");
            borraGrafica(x,y);
        }
             
    gfx_flush();
}
}
void borraGrafica(int x,int y){
    gfx_color(0,0,0);
    gfx_point(x,-y+300);
}

void pintaGrafica(int x,int y){
    gfx_color(100,135,25);
    gfx_point(x,-y+300);
}