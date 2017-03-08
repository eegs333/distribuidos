#include "Primos.h"
#include <iostream>
#include <vector>

using namespace std;



 void Primos::criba(int numero){

	//cuantos=0;

	for(int i=2; i*i <= numero; i++)
	{
        if(!primos[i])
            for(int j=2; i*j <= numero; j++)
                primos[i*j] = true;
    }
        
    for(int i = 2; i <= numero; i++)
    {
    	if(!primos[i])
    	{
            primosdec[i] = i;
        }
    }    

    cout<< "Los numeros primos encontrados hasta el numero " <<numero <<" son: "<<endl;
	
	for(int i=2; i <= numero ;i++)
	{
            if(!primos[i])
            {
    		  cout <<primosdec[i]<<endl;
            }
    }
}