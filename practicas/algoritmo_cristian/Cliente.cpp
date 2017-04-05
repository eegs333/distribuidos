#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstring>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
int puerto = 7200;
// lolstruct timeval t1;
int main(int argn, char* args[])
{
    struct timeval now;
    struct timeval t0;
    struct timeval t1;
    struct timeval time;
    struct tm* ptm;
	  char time_string[40];
	  long milliseconds;
    if (argn >= 2) {
        SocketDatagrama socket(sizeof(now));
        PaqueteDatagrama paqueteEnviado((char *)&now, sizeof(now), args[1], puerto);
        gettimeofday (&t0, NULL);
        socket.envia(paqueteEnviado);
        PaqueteDatagrama paqueteRecibido(sizeof(now));
        socket.recibe(paqueteRecibido);
        gettimeofday (&t1, NULL);
        memcpy(&now, paqueteRecibido.obtieneDatos(), sizeof(now));
        printf("%ld\n", now.tv_usec);
        printf("%ld\n", now.tv_sec);
        timersub(t1.tv_sec,t0.tv_sec)
        time.tv_sec=(-)/2 + now.tv_sec;
        time.tv_usec=(t1.tv_usec-t0.tv_usec)/2 + now.tv_usec;
        ptm = localtime (&time.tv_sec);
    	  strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
    	  milliseconds = time.tv_usec / 1000;
    	  printf ("%s.%03ld\n", time_string, milliseconds);
    } else {
        printf("Uso: %s ip\n",args[0]);
    }

}
