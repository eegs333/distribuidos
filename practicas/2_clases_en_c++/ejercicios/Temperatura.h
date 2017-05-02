#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura{
private:
	float kelvin;
	float celcius;
	float fahrenheit;
public:
	void setTempKelvin(float);
	void setTempFahrenheit(float);
	void setTempCelsius(float);
	void getTempKelvin();
	void getTempFahrenheit();
	void getTempCelsius();
};
#endif /* TEMPERATURA_H_ */
