#include "Fraccion.h"
#include <iostream>
using namespace std;

int main()
{
	Fraccion frac;
	frac.setFraccion(5,7);
	//frac.getDivision();
	std::cout << frac.getDivision() << '\n';
}
