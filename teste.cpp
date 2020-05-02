#include <iostream>
using namespace std;

int main(){
	char data[30] = "Ola;Eu sou giulliano; ola;\n";
	for(int i = 0; i < 30; i++){
		char chr = (char)data[i];
		if(chr == ';') cout << "Fez" << endl;
		else if(chr == '\n') cout << "Ok" << endl;
		else cout << "Normal" << endl;
	}
	return 0;
}
