#include "Coordenada.h"
#ifndef RECTANGULO_H
#define RECTANGULO_H

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
 };

#endif /* RECTANGULO_H */

