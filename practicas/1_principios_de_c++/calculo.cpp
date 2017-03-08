#include<iostream>
#include <math.h>
using namespace std;
int main(){
	double a, b, c, d, e;
  	for(int i = 1; i < (1e4); i++){
  		a += sin(i);
  		b += cos(i);
  		c += tan(i);
  		d += log10(i);
  		e += sqrt((double)i);
  	}
  	cout << a << " "<< b << " " << c << " "<< d << " "<< e<< endl; 
	return 0;
}