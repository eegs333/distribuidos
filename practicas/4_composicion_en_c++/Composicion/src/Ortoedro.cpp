/*
 * Ortoedro.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: esgi
 */
#include "Coordenada.h"
#include "Ortoedro.h"

namespace std {

Ortoedro::Ortoedro() : M(0,0,0), N(0,0,0) { }
Ortoedro::Ortoedro(double x1, double y1, double z1, double x2, double y2, double z2) : M(x1, y1, z1), N(x2, y2, z2) { }

Coordenada Ortoedro::obtieneM()
{
	return M;
}

Coordenada Ortoedro::obtieneN()
{
	return N;
}

double Ortoedro::obtieneArea(){
	int largo, ancho, alto;
	double area;
	largo = obtieneN().obtenerX() - obtieneM().obtenerX();
	ancho = obtieneN().obtenerY() - obtieneM().obtenerY();
	alto = obtieneN().obtenerZ() - obtieneM().obtenerZ();
	area = 2 * ((largo * ancho) + (ancho * alto) + (largo * alto));
	return area;

}


} /* namespace std */
