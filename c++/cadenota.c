#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *rand_string(char *str, size_t size)
{
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    strcat(str," ");
    return str;
}

int main(void) {

	int size = 70304;
	time_t t;
	srand((unsigned) time(&t));
	char cstr[4];
	char cstr2[size];
	char word[]="IPN";
	int i;
	while(1){
		rand_string(cstr,4);
		if(strstr(cstr, word) != NULL) {
		    i++;
		}
		strcat(cstr2,cstr);
		if(strlen(cstr2)==sizeof(cstr2))
			break;
	}
			printf("%s",cstr2);
			printf("\nSe encontraron %d IPN's",i);
	return EXIT_SUCCESS;
}
