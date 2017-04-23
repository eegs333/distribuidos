#include <stdio.h>
#include <stdlib.h>
#include <string.h> //list_files
#include <fcntl.h> //list_files
#include <unistd.h> //list_files
#include <cstdlib> //list_files
#include <dirent.h> //list_files
#include <vector> //list_files
#include <iostream> //list_files
#include <fstream> //search_word
#include <string> //search_word
#include <sstream> //search_word
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

int puerto = 7200;
using namespace std;

//obtiene la lista de archivos de un directorio
vector<string> list_files(const char *ldir){
	//cout << "iniciando list_files.... " << endl;
	vector<string> files;
	DIR *dir;
	struct dirent *ent;
	int offset, origen;
	if ((dir = opendir (ldir)) != NULL) {

  while ((ent = readdir (dir)) != NULL) {
		if(ent->d_name[0] !='.'){
			files.push_back(ent->d_name);
		}
  }
  closedir (dir);
	}
	return files;
}

//estructura para los datos a devolver
struct c_word{
	//const char* fileName;
	//const char* word;
	char fileName[32];
	char word[32];
	char offset[32];
};

//funcion que busca la cadena
c_word search_word(const char *word, const char *file, const char *dir){

	c_word charSearch;
	int ocurrences_count = 0;
	int array_size = 1024;
	char * array = new char[array_size];
	int position = 0;
	int word_size = 0;
	int offsets[10];
	char namFil[32];
	char result[32];
	char buffer [32];
	strcpy(namFil,dir);
	strcat(namFil,file);

	for(int i = 0; word[i] != '\0'; i++){
    word_size++;
  }

	strcpy(charSearch.fileName,file);
	strcpy(charSearch.word,word);
	//charSearch.fileName = file;
	//charSearch.word = word;
	//strcpy(result,"offset = ");

	ifstream fin(namFil);
	cout << "namFil: " <<namFil << endl;
	if(fin.is_open()){
  	while(!fin.eof() && position < array_size){
			fin.get(array[position]);
			position++;
		}
		array[position-1] = '\0';

  	for(int i = 0; array[i] != '\0'; i++){
			for(int j = 0; word[j] != '\0' && j < 20 ; j++){
        if(array[i] != word[j]){
          break;
        }
        else{
          i++;
          if(word[j+1] == '\0'){
						offsets[ocurrences_count] = i-word_size;
						ocurrences_count++;
          }
        }
      }
		}
			strcpy(result,"offset = ");
			for(int i = 0; i < ocurrences_count; i++){
				snprintf(buffer, sizeof(buffer), "%d,", offsets[i]);
				strcat(result,buffer);
				//cout << result << endl;
			}
			strcpy(charSearch.offset,result);
			//charSearch.offset = result;
	}
	else{
		cout << "File could not be opened." << endl;
	}
	//cout << "finalizando search_word.... " << endl;
	return charSearch;
}

int main(int argc, char** argv){
	char *dir = argv[1];
	char word[20];
	c_word sw;

	SocketDatagrama socket(puerto);
	printf("Esperando mensajes...\n");
	while (1) {
		PaqueteDatagrama paqueteRecibido(sizeof(word));
    socket.recibe(paqueteRecibido);
    char* rword=paqueteRecibido.obtieneDatos();
    cout <<"Cadena a buscar: "<<rword<<"\n";
		vector<string> str_vec = list_files(dir);
	     for(vector<string>::iterator it_file = str_vec.begin(); it_file != str_vec.end(); it_file++) {
					sw = search_word(rword,(*it_file).c_str(),dir);
					//char b[sizeof(sw)];
					//memcpy(b, sw, sizeof(sw));
					//char* sw_bytes = reinterpret_cast<char*>(sw);
					PaqueteDatagrama paqueteEnviado((char *)&sw, (sizeof(sw)), paqueteRecibido.obtieneDireccion(),puerto);
					paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
					socket.envia(paqueteEnviado);
					//cout << sw << endl;
					cout << sw.fileName << endl;
					cout << sw.word << endl;
					cout << sw.offset << endl;
	     }
		}
}
