#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int puerto = 7200;
int criba(int numero); 
int primos[10000];
int primosdec[10000];

int main(int argc, char *argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], numero, res;
   char cadena[4];
   int len=20;
   char buffer[len];

   printf("%s\n", argv[1]);
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);
   /*copia la direccion*/
   memcpy(cadena, &(msg_to_server_addr.sin_addr.s_addr), 4);
   for(int i=0; i<4; i++){
     printf("%i\n",cadena[i]);
   }

   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;

   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));

   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&numero, sizeof(int), 0, NULL, NULL);
   inet_ntop(AF_INET, &(msg_to_server_addr.sin_addr), buffer, len);
   printf("address:%s\n",buffer);
   printf("port:%d\n", (int)ntohs(msg_to_server_addr.sin_port));
   criba(numero);
    
   //printf("2 + 5 = %d\n", numero);
   close(s);
}

int criba(int numero){
   numero;

   for(int i=2; i*i <= 1000; i++)
   {
        if(primos[i]!=1)
            for(int j=2; i*j <= numero; j++)
                primos[i*j] = 1;
   }
        
    for(int i = 2; i <= 1000; i++)
    {
      if(primos[i] !=1)
      {
            primosdec[i] = i;
        }
    }
   
   for(int i=2; i <= 1000 ;i++)
   {
            if(primosdec[i]==numero)
            {
              printf("El numero %d es primo \n",numero);
              exit(0);
            }
            
   }
   printf("El numero %d no es primo \n", numero);   
    
}
