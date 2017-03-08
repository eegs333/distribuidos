#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int stringLength = sizeof(alpha) - 1;
int size = 70304;

string cadenota;

string genRandom()
{
	 string token;
	 for (int i = 0; i < 3; i++){
		 token += alpha[rand() % stringLength];
	 }
	 token += " ";
	 return token;
}

int main()
{
    while(true)
    {
        cout << genRandom();
        cadenota +=genRandom();
        if (cadenota.length()==70304)
        	exit (0);
    }
    return 0;

}
