#include "Temperatura.h"
#include <iostream>
using namespace std;

void Temperatura::setTempKelvin(float kel){
  kelvin = kel;
}

void Temperatura::setTempFahrenheit(float fahr){
  float cel;
  fahrenheit = fahr;
  cel = fahr-32*(5/9);
  kelvin = cel + 273.15;
}

void Temperatura::setTempCelsius(float cel){
  celcius = cel;
  kelvin = cel + 273.15;
}

void Temperatura::getTempKelvin(){
  cout << "Los grados Kelvin son: " << kelvin << endl;
}

void Temperatura::getTempFahrenheit(){
  cout << "Los grados Fahrenheit son: " << fahrenheit << endl;
}

void Temperatura::getTempCelsius(){
  cout << "Los grados Celsius son: " << celcius << endl;
}
