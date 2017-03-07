#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int stringLength = sizeof(alpha) - 1;
int size = 70304;
int counter =0;
string cadenota;
string word="IPN";

string genRandom()
{
	 string token;
	 for (int i = 0; i < 3; i++){
		 token += alpha[rand() % stringLength];
	 }
	 int pos;
	 	 if ((pos = token.find(word)) != token.npos) {
	 		 counter +=1;
	 	 }
	 token +=" ";
	 return token;
}

int main(){

	srand(time(NULL));

    while(true)
    {
        cout << genRandom();
        cadenota +=genRandom();
        if (cadenota.length()==70304){
        	cout << "\nSe encontraron " << counter << " IPN's";
        	exit (0);
        }
    }
}
