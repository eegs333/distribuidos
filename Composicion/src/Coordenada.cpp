/*
 * Coordenada.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: esgi
 */

#include "Coordenada.h"

namespace std {

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{ }

double Coordenada::obtenerX()
{
	return x;
}

double Coordenada::obtenerY()
{
	return y;
}

double Coordenada::obtenerZ()
{
	return z;
}

} /* namespace std */
