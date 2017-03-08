/*
 ============================================================================
 Name        : cadenaC.c
 Author      : esgi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *rand_string(char *str, size_t size)
{
	srand((unsigned int) time(0));
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    strcat(str, " ");
    return str;
}

int main(void) {

	int i=0;
	char cstr[3];
	char cadenota[1000]="";
	while(1){
		i++;
		rand_string(cstr,4);
		printf("%s",cstr);
		 memset(cstr, 0, sizeof cstr);
		if (i==10 ){
			break;
		}
	}

	printf("%s",cadenota);
	return EXIT_SUCCESS;
}
