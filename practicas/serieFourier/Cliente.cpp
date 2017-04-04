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

int main(int argn, char* args[])
{
    if (argn >= 2) {
        int num[2];
        int res;

        num[0] = 0;
        num[1] = 1; /*rellena el mensaje */

            printf("Tratando de crear socket\n");
        SocketDatagrama socket(65536);
            printf("Socket creado\n");
        PaqueteDatagrama paqueteEnviado((char*)num, 100, args[1], puerto);
            printf("Paquete creado\n");

        socket.envia(paqueteEnviado);
            printf("Paquete enviado\n");

        PaqueteDatagrama paqueteRecibido(sizeof(int));
            printf("Esperando paquete\n");
        socket.recibe(paqueteRecibido);
            printf("Paquete recibido\n");
        printf("2 + 5 = %d\n", *((int*)paqueteRecibido.obtieneDatos()));
    } else {
        printf("Uso: %s ip\n",args[0]);
    }

}
