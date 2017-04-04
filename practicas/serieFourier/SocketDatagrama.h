#ifndef SOCKET_DATAGRAMA_H
#define SOCKET_DATAGRAMA_H

#include <sys/types.h>
#include <sys/socket.h>
#include "PaqueteDatagrama.h"
#include <netinet/in.h>

class SocketDatagrama {
public:
    SocketDatagrama(int);
    ~SocketDatagrama();
        // Recibe un datagrama proveniente de este socket
    int recibe(PaqueteDatagrama &p);
        //Envia un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama &p);
private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s;
};

#endif
