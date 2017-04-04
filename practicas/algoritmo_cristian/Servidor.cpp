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
	  long milliseconds;
		char IP[] = "127.0.0.1";

	  gettimeofday (&tv, NULL);
		printf("%ld\n",tv.tv_sec);
		printf("%ld\n",tv.tv_usec);
	  ptm = localtime (&tv.tv_sec);
	  strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
	  milliseconds = tv.tv_usec / 1000;
	  printf ("%s.%03ld\n", time_string, milliseconds);
    SocketDatagrama socket(puerto);
		PaqueteDatagrama paqueteRecibido(sizeof(tv));
		//PaqueteDatagrama paqueteEnviado(out,1,IP,puerto);
		PaqueteDatagrama paqueteEnviado((char *)&tv,sizeof(tv),IP,puerto);
		printf("Esperando mensajes...\n");
		while (1) {
      		printf("%d\n",socket.recibe(paqueteRecibido));
					paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
					socket.envia(paqueteEnviado);
					printf("ENVIANDO DATOS\n" );
    }
}
