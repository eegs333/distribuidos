#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//#Fecha::Fecha(int dd, int mm, int aaaa)
//#{
//# mes = mm;
//# dia = dd;
//# anio = aaaa;
//#}
Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{
if((mes < 1) || (mes > 12)){
cout << "Valor ilegal para el mes!\n";
exit(1);
}
if((dia < 1) || (dia > 31)){
  cout << "Valor ilegal para el dia!\n";
  exit(1);
}
if((anio < 1) || (anio > 2017)){
cout << "Valor ilegal para el año!\n";
exit(1);
}
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
 anio = aaaa;
 mes = mm;
 dia = dd;
 
 if((mes < 1) || (mes > 12)){
 cout << "Valor ilegal para el mes!\n";
 exit(1);
 }

 return;
}
void Fecha::muestraFecha()
{
 cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
 return;
}

void Fecha::leapyr(int aaaa)
{
    anio = aaaa;
    int ia = 0;
    for (int a = 1; a == 2017; a = a + 1){
    if (a % 4)
        ia=ia+1;
    }
    cout << "años" << ia << endl;
    return;
}
