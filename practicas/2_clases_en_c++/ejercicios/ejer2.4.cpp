#include <iostream>
#include "Temperatura.h"
using namespace std;

int main(int argc, char const *argv[]) {
	float grados;
	char escala;
	Temperatura temp;
	cout << "Escala de temperatura? kelvin (k), celcius (c), fahrenheit (f): ";
	cin >> escala;
	cout << "Grados a convertir: ";
	cin >> grados;
	if (escala == 'k'){
		temp.setTempKelvin(grados);
		temp.getTempKelvin();
	}
	else if (escala == 'c'){
		temp.setTempCelsius(grados);
		temp.getTempKelvin();
	}
	else if (escala == 'f'){
		temp.setTempFahrenheit(grados);
		temp.getTempKelvin();
	}

	cout << "Escala de temperatura? kelvin (k), celcius (c), fahrenheit (f): ";
	cin >> escala;

	if (escala == 'k'){
		temp.getTempKelvin();
	}
	else if (escala == 'c'){
		temp.getTempCelsius();
	}
	else if (escala == 'f'){
		temp.getTempFahrenheit();
	}

	return 0;
}
