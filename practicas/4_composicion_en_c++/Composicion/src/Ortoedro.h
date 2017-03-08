/*
 * Ortoedro.h
 *
 *  Created on: Mar 6, 2017
 *      Author: esgi
 */
#include "Coordenada.h"
#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_

namespace std {

class Ortoedro {

private:
	Coordenada M;
	Coordenada N;
public:
	Ortoedro();
	Ortoedro(double x1, double y1, double z1, double x2, double y2, double z2);
	Coordenada obtieneM();
	Coordenada obtieneN();
	void obtieneVertices();
	double obtieneArea();
	void obtieneVolumen();


};

} /* namespace std */

#endif /* ORTOEDRO_H_ */
