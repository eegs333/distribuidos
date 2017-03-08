#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa)
{
mes = mm;
dia = dd;
anio = aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
anio = aaaa;
mes = mm;
dia = dd;
return;
}
void Fecha::muestraFecha()
{
cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
return;
}

int Fecha::masVieja(Fecha fecha1, Fecha fecha2){
  if (fecha1 > fecha2)
  return 1;
}

int main()
{
Fecha a, b, c(21, 9, 1973);
b.inicializaFecha(17, 6 , 2000);
a.masVieja(b,c);
}
