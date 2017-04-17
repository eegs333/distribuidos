#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <dirent.h>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains file input/output functions
int puerto = 7200;

using namespace std;

int main(void)
{

	DIR *dir;
	struct dirent *ent;
	int offset, origen;
	if ((dir = opendir ("../libros/")) != NULL) {
  while ((ent = readdir (dir)) != NULL) {
		if(ent->d_name[0] !='.'){
			printf ("%s\n", ent->d_name);
			char namFil[32];
			strcpy(namFil,"../libros/");
			strcat(namFil, ent->d_name);
			if((origen = open(namFil, O_RDONLY)) == -1){
		    exit(-1);
			 	printf("%d\n",origen );
		  }
		}
  }
  closedir (dir);
	} else {
  	perror ("");
  	return EXIT_FAILURE;
	}

	char* cadena = new char[strlen(cadena)];
	SocketDatagrama socket(puerto);
  printf("Esperando mensajes...\n");
  while (1) {
		PaqueteDatagrama paqueteRecibido(sizeof(cadena));
    socket.recibe(paqueteRecibido);
    char* s=paqueteRecibido.obtieneDatos();
    cout <<paqueteRecibido.obtieneDatos()<<"\n";
		}
}

int search(char wd[20], char file[20]){
	int ocurrences_count = 0;
	char word[20];  //this array will save user input
	int array_size = 1024; // define the size of character array
	char * array = new char[array_size]; // allocating an array of 1kb
	int position = 0; //this will be used incremently to fill characters in the array

	//prompting user to enter a word to be search in the file
	cout << "Please enter the word to  search in file : ";
	cin.getline(word,19); //reading user input of max 19 characters because our word array size in 20
	int word_size = 0;
	//this loop is calculating the length of input word
	for(int i = 0; word[i] != '\0'; i++)
	{
		word_size++;
	}

	ifstream fin(file); //opening an input stream for file test.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
	stream could not be opened.*/
	if(fin.is_open())
	{
		//file opened successfully so we are here
		cout << "File Opened successfully!!!. Reading data from file into array" << endl;
		//this loop run until end of file (eof) does not occur
		while(!fin.eof() && position < array_size)
		{
			fin.get(array[position]); //reading one character from file to array
			position++;
		}
		array[position-1] = '\0'; //placing character array terminating character

		//this loop is searching for the word in the array
		for(int i = 0; array[i] != '\0'; i++)
		{
			for(int j = 0; word[j] != '\0' && j < 20 ; j++)
			{
				if(array[i] != word[j])
				{
					break;
				}
				else
				{
					i++;
					if(word[j+1] == '\0')
					{
						cout << "Word Found in File at position " << (i-word_size) << endl;
						ocurrences_count++;
					}
				}
			}
		}
		cout << "Total occurences found : " << ocurrences_count << endl;
	}
	else //file could not be opened
	{
		cout << "File could not be opened." << endl;
	}
	return 0;
}
