#include <iostream>
#include "Fraccion.h"

void Fraccion::setFraccion(int num, int den){
	numerador = num;
	denominador = den;
}

double Fraccion::getDivision(){
	double div;
		div = numerador / double(denominador);
	return div;
}

void Fraccion::getMinima(){
	
}
