#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
int puerto = 7200;

using namespace std;

int main(void)
{

	DIR *dir;
	struct dirent *ent;
	int offset, origen;
	if ((dir = opendir ("../libros/")) != NULL) {
  while ((ent = readdir (dir)) != NULL) {
		if(ent->d_name[0] !='.'){
			printf ("%s\n", ent->d_name);
			char namFil[32];
			strcpy(namFil,"../libros/");
			strcat(namFil, ent->d_name);
			if((origen = open(namFil, O_RDONLY)) == -1){
		    exit(-1);
			 	printf("%d\n",origen );
		  }
		}
  }
  closedir (dir);
	} else {
  	perror ("");
  	return EXIT_FAILURE;
	}

	char* cadena = new char[strlen(cadena)];
	SocketDatagrama socket(puerto);
  printf("Esperando mensajes...\n");
  while (1) {
		PaqueteDatagrama paqueteRecibido(sizeof(cadena));
    socket.recibe(paqueteRecibido);
    char* s=paqueteRecibido.obtieneDatos();
    cout <<paqueteRecibido.obtieneDatos()<<"\n";
		}
}
