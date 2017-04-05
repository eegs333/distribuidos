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
int main(int argc, char** argv) {
		char IP[] = "127.0.0.1";
		struct timeval tv;
		tv = gettime();
    SocketDatagrama socket(puerto);
		PaqueteDatagrama paqueteRecibido(sizeof(tv));
		PaqueteDatagrama paqueteEnviado((char *)&tv,sizeof(tv),IP,puerto);
		printf("Esperando solicitud de hora...\n");
		while (1) {
					if (socket.recibe(paqueteRecibido)){
						tv = gettime();
						PaqueteDatagrama paqueteEnviado((char *)&tv,sizeof(tv),IP,puerto);
						paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
						socket.envia(paqueteEnviado);
						printf("Enviando hora...\n" );
					}
    }
}
