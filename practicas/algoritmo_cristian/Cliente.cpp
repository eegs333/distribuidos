#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstring>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
int puerto = 7200;
// lol
int main(int argn, char* args[])
{

    if (argn >= 2) {
        SocketDatagrama socket(sizeof(now));
        PaqueteDatagrama paqueteEnviado((char *)&now, sizeof(now), args[1], puerto);
        socket.envia(paqueteEnviado);
        PaqueteDatagrama paqueteRecibido(sizeof(int));
        printf("Esperando paquete\n");
        socket.recibe(paqueteRecibido);
        printf("Paquete recibido\n");
        //printf("%d\n", *((int*)paqueteRecibido.obtieneDatos()));
        struct timeval now;
        memcpy(&now, paqueteRecibido.obtieneDatos(), sizeof(now));
        printf("%ld\n", now.tv_usec);
    } else {
        printf("Uso: %s ip\n",args[0]);
    }

}
