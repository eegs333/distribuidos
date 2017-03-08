#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){
	
	double i=0,a=1;
	double seno=0, coseno=0, tangente=0, raizCuad=0, logaritmo=0;
	int MAx=16000000;
	//struct timeval tvalBefore, tvalAfter;
	//gettimeofday(&tvalBefore,NULL);
	clock_t start = clock();

	while(i<MAx)
	{
		seno += sin(i);
		coseno += cos(i);
		tangente += tan (i);
		logaritmo += log(a);
		i++;
		a++;
		
		//printf("i= %lf", i);
	}
		printf("\ni= %lf", i);
		printf("\nEl seno es: %lf", seno);
		printf("\nEl coseno es: %lf", coseno);
		printf("\nLa tangente es: %lf", tangente);
		printf("\nEl logaritmo es: %lf", logaritmo); 
		printf("\nLa raiz cuadrada es: %lf", raizCuad);
		//gettimeofday(&tvalAfter,NULL);
		printf("\nTiempo transcurrido: %0.3f microsegundos", ((double)clock() - start));
	return(0);

}