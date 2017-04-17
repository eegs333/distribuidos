#include <stdio.h>
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
struct s_word{
	string fileName;
	string word;
	string offset;
};

//funcion que busca la cadena
s_word search_word(const char *word, const char *file, const char *dir){

	s_word newSearch;
	int ocurrences_count = 0;
	int array_size = 1024;
	char * array = new char[array_size];
	int position = 0;
	int word_size = 0;
	char namFil[32];
	strcpy(namFil,dir);
	strcat(namFil,file);
	vector<int> offsets;

	for(int i = 0; word[i] != '\0'; i++){
    word_size++;
  }
	newSearch.fileName = file;
	newSearch.word = word;
	newSearch.offset = "offset = ";

	ifstream fin(namFil);

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
						offsets.push_back(i-word_size);
						ocurrences_count++;
          }
        }
      }
		}

			for(vector<int>::iterator it = offsets.begin(); it != offsets.end(); it++) {
				ostringstream ostr;
				ostr << *it;
				string Result = ostr.str();
				newSearch.offset.append(Result + " ");
			}
	}
	else{
		cout << "File could not be opened." << endl;
	}
	return newSearch;
}

int main(int argc, char** argv){
	char *dir = argv[1];
	//char *word = argv[2];
	char word[20];
	s_word sw;
	//char* sw_bytes = reinterpret_cast<char*>(&sw);




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
					char b[sizeof(sw)];
					memcpy(b, &sw, sizeof(sw));
					//char* sw_bytes = reinterpret_cast<char*>(&sw);
					PaqueteDatagrama paqueteEnviado(b,sizeof(b),paqueteRecibido.obtieneDireccion(),puerto);
					paqueteEnviado.inicializaPuerto(paqueteRecibido.obtienePuerto());
					socket.envia(paqueteEnviado);
					cout << b << endl;
					cout << sw.fileName << endl;
					cout << sw.offset << endl;
	     }
		}
}
