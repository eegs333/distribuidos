/*
 * Rectangulo.h
 *
 *  Created on: Mar 6, 2017
 *      Author: esgi
 */
#include "Coordenada.h"
#ifndef RECTANGULO_H_
#define RECTANGULO_H_

namespace std {

class Rectangulo
{
	private:

	Coordenada superiorIzq;
	Coordenada inferiorDer;

	public:

	Rectangulo();
	Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);

	void imprimeEsq();

	Coordenada obtieneSupIzq();
	Coordenada obtieneInfDer();

	double obtieneArea();
};

} /* namespace std */

#endif /* RECTANGULO_H_ */
