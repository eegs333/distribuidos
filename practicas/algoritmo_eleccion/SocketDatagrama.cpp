#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstdio>

SocketDatagrama::SocketDatagrama(int port) {
    s = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero((char*) &direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

    bzero((char*) &direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
}

SocketDatagrama::~SocketDatagrama() {
    close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
    unsigned int length = sizeof(direccionForanea);
    int bytes = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &length);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
    return bytes;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    direccionForanea.sin_port = htons(p.obtienePuerto());
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
