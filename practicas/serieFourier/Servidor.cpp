#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
int puerto = 7200;
int main(void) {
	char out[1024] = "V";
    int f,cont=0;
    SocketDatagrama socket(puerto);
    PaqueteDatagrama paqueteRecibido(65536);
    PaqueteDatagrama paqueteEnviado(out,1,"10.100.67.38",puerto);
        printf("Esperando mensajes...\n");
    while (1) {
        printf("%d\n",socket.recibe(paqueteRecibido));
        cont++;
        printf("%d\n",cont );
       paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
       socket.envia(paqueteEnviado);
       printf("ENVIANDO DATOS\n" );
    }
}
