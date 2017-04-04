#include <stdio.h>
#include <math.h>
#include "gfxModified.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>

//using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600




int main()
{
	
    gfx_open(ANCHURA, ALTURA, "Ejemplo Micro Juego GFX");
 
    
    gfx_flush();
    usleep(18000);

}
