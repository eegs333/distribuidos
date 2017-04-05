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
struct timeval gettime() {
	struct timeval tv;
	struct tm* ptm;
	char time_string[40];
	//long milliseconds;
	//obtiene tiempo
	gettimeofday (&tv, NULL);
	printf("%ld\n",tv.tv_sec);
	printf("%ld\n",tv.tv_usec);
	//formato tiempo
	ptm = localtime (&tv.tv_sec);
	strftime (time_string, sizeof (time_string), "%H:%M:%S", ptm);
	//milliseconds = tv.tv_usec / 1000;
	printf ("%s\n", time_string);
	return tv;
}
int main(int argn, char* args[])
{
    struct timeval now;
    struct timeval tser;
    struct timeval t0;
    struct timeval t1;
    struct timeval ttmp;
    struct tm* ptm;
	  char time_string[40];
	  long milliseconds;
    if (argn >= 2) {
        SocketDatagrama socket(sizeof(tser));
        PaqueteDatagrama paqueteEnviado((char *)&tser, sizeof(tser), args[1], puerto);
        gettimeofday (&t0, NULL);
        socket.envia(paqueteEnviado);
        PaqueteDatagrama paqueteRecibido(sizeof(tser));
        socket.recibe(paqueteRecibido);
        gettimeofday (&t1, NULL);
        memcpy(&tser, paqueteRecibido.obtieneDatos(), sizeof(tser));
        printf("%ld\n", tser.tv_usec);
        printf("%ld\n", tser.tv_sec);
        timersub(&t1,&t0,&ttmp);
        ttmp.tv_sec = ttmp.tv_sec / 2;
        ttmp.tv_usec = ttmp.tv_usec / 2;
        timeradd(&tser,&ttmp,&now);
        ptm = localtime (&now.tv_sec);
    	  strftime (time_string, sizeof (time_string),"%H:%M:%S", ptm);
    	  milliseconds = now.tv_usec / 1000;
        printf("%ld\n", now.tv_usec);
        printf("%ld\n", now.tv_sec);
    	  printf ("%s.%03ld\n", time_string, milliseconds);
    } else {
        printf("Uso: %s ip\n",args[0]);
    }
}
