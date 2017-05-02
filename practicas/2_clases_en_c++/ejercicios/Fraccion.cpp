#include <iostream>
#include "Fraccion.h"
using namespace std;

void Fraccion::setFraccion(int num, int den){
	numerador = num;
	denominador = den;
}

double Fraccion::getDivision(){
	double div;
		div = numerador / double(denominador);
	return div;
}

void Fraccion::getMinima(){
	int *num_mcd;
	int *den_mcd;
	int mcd=-1;
	int mcd_tmp;
	int num;
	int den;
	int num_count = 0;
	int den_count = 0;
	num_mcd = new int[numerador];
	den_mcd = new int[denominador];

	for(int i = 1; i <= numerador; i++ ){
		if(numerador%i == 0){
			num_mcd[num_count] = i;
			//cout << "numerador: " << num_mcd[num_count] << endl;
			num_count += 1;
		}
	}
	//cout << num_count << endl;

	for(int i = 1; i <= denominador; i++ ){
		if(denominador%i == 0){
			den_mcd[den_count] = i;
			//cout << "denominador: " << den_mcd[den_count] << endl;
			den_count += 1;
		}
	}
	//cout << den_count << endl;

	den_count--;
	num_count--;
	while(true){
		if(den_mcd[den_count] < num_mcd[num_count]){
			mcd_tmp = den_mcd[den_count];
			//cout << "mcd_tmp: " << mcd_tmp << endl;
			for(int i = num_count; i > 0; i-- ){
				if(mcd_tmp == num_mcd[i]){
					mcd = mcd_tmp;
					break;
				}
			}
			if(mcd==-1){
				num_count--;
			}
			else{
		//		cout << mcd << endl;
				break;
			}
		}
		else if(num_mcd[num_count] < den_mcd[den_count]){
			mcd_tmp = num_mcd[num_count];
			//cout << "mcd_tmp: " << mcd_tmp << endl;
			for(int i = den_count; i > 0; i-- ){
				if(mcd_tmp == den_mcd[i]){
					mcd = mcd_tmp;
					break;
				}
			}
			if(mcd==-1){
				den_count--;
			}
			else{
			//	cout << mcd << endl;
				break;
			}
		}
		else if (num_mcd[num_count] == den_mcd[den_count]){
			mcd = num_mcd[num_count];
			break;
		}

		else{
			cout << "Minima expresion: " << numerador << "/" << denominador << endl;
			break;
		}

	}

	num = numerador / mcd;
	den = denominador / mcd;
	if(den == 1){
			cout << "Minima expresion: " << num << endl;
	}
	else
		cout << "Minima expresion: " << num << "/" << den << endl;

}
