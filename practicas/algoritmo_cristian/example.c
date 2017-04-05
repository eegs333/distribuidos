/*
gcc example.c gfx.c -o example -lX11 -lm

*/

#include <stdio.h>
#include "gfx.h"

int main()
{
	int ysize = 300;
	int xsize = 300;
	const char cadena[20] = "eegs333";
	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	gfx_line(100,100,200,100);
	gfx_line(200,100,150,150);
	gfx_line(150,150,100,100);
	gfx_text(50, 50, cadena );

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
