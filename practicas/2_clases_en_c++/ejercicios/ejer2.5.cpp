#include "Fraccion.h"
#include <iostream>
using namespace std;

int main()
{
	int num, den;
	Fraccion frac;
	std::cout << "Numerador: ";
	std::cin >> num;
	std::cout << "Denominador: ";
	std::cin >> den;
	if(den!=0){
		frac.setFraccion(num,den);
		std::cout << "Division: " <<frac.getDivision() << '\n';
		frac.getMinima();
	}
	else
		std::cout << "Error el denominador debe ser diferente de 0" << '\n';

}
