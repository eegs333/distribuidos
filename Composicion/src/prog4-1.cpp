#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main( )
{

	//Rectangulo rectangulo1(Coordenada(2,3),Coordenada(5,1));
    //Rectangulo rectangulo1(2,3,5,1);
	Ortoedro orto(0,0,0,5,5,5);

double ancho, alto, area;


cout << "Calculando el área de un rectángulo dadas sus coordenadas en un planocartesiano:\n";

//rectangulo1.imprimeEsq();


//alto = rectangulo1.obtieneSupIzq().obtenerY() - rectangulo1.obtieneInfDer().obtenerY();

//ancho = rectangulo1.obtieneInfDer().obtenerX() - rectangulo1.obtieneSupIzq().obtenerX();

//area = rectangulo1.obtieneArea();
area = orto.obtieneArea();
cout << "El área del rectángulo es = " << area << endl;

return 0;
 }


