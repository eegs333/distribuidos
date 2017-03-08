/*
 * Coordenada.h
 *
 *  Created on: Mar 6, 2017
 *      Author: esgi
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

namespace std {

class Coordenada
{
	private:

	double x;
	double y;
	double z;

	public:

	Coordenada(double = 0, double = 0, double = 0);

	double obtenerX();
	double obtenerY();
	double obtenerZ();

};

} /* namespace std */

#endif /* COORDENADA_H_ */
