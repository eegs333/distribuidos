#ifndef PRIMOS_H_
#define PRIMOS_H_
#include <vector>
using namespace std; 


class Primos{
	
	private:
	
	   vector <bool> primos;
	   vector <int> primosdec;

    public:
    Primos(): primos(1000), primosdec(1000) {};
    void criba(int numero); 
};

 #endif