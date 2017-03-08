#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>


int puerto = 7200;
int criba(int numero); 
int primos[10000];
int primosdec[10000];

int main(void)
{
   int num[2],numero;
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
  
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
  
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   
   while(1) {
      recvfrom(s, (char *)numero, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
       
      //res = num[0] + num[1];
      res = criba(numero);
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}
 
 int criba(int numero){
   int n=numero;

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

    //printf("Los numeros primos encontrados hasta el numero %d son: ", numero);
   
   for(int i=2; i <= 1000 ;i++)
   {
            if(primos[i]==numero)
            {
              return 1;
              printf("Es primo");
              exit(0); 
            }

    }    
    return 0;
}
