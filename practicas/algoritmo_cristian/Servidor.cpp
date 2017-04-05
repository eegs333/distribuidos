#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
int puerto = 7200;
int main(int argc, char** argv) {
		struct timeval tv;
	  struct tm* ptm;
	  char time_string[40];
		char time_hr[10];
	  long milliseconds;
		char IP[] = "127.0.0.1";
		//obtiene tiempo
		gettimeofday (&tv, NULL);
		printf("%ld\n",tv.tv_sec);
		printf("%ld\n",tv.tv_usec);
		//formato tiempo
	  ptm = localtime (&tv.tv_sec);
	  strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
		strftime (time_hr, sizeof (time_hr), "%H", ptm);
		milliseconds = tv.tv_usec / 1000;
	  printf ("%s.%03ld\n", time_string, milliseconds);
		printf ("%s\n", time_hr);
    SocketDatagrama socket(puerto);
		PaqueteDatagrama paqueteRecibido(sizeof(tv));
		PaqueteDatagrama paqueteEnviado((char *)&tv,sizeof(tv),IP,puerto);
		printf("Esperando mensajes...\n");
		while (1) {
      		//printf("%d\n",socket.recibe(paqueteRecibido));
					if (socket.recibe(paqueteRecibido)){
						gettimeofday (&tv, NULL);
						printf("%ld\n",tv.tv_sec);
						printf("%ld\n",tv.tv_usec);
						ptm = localtime (&tv.tv_sec);
					  strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
					  milliseconds = tv.tv_usec / 1000;
					  printf ("%s.%03ld\n", time_string, milliseconds);
						PaqueteDatagrama paqueteEnviado((char *)&tv,sizeof(tv),IP,puerto);
						paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
						socket.envia(paqueteEnviado);
						printf("ENVIANDO DATOS\n" );
					}
    }
}
