#include <iostream>
#include <iomanip>
using namespace std;

double raiz(double x){
	double r=x, t=0;
	while(t!=r){
		t=r;
		r=(x/r + r)/2;
	}
	return r;
}

int main(){

	int n;
	cout << "Numero entero a calcular: ";
	cin >> n;
	cout << fixed << setprecision(4);
	cout << raiz(n) << endl;
	return 0;
}
