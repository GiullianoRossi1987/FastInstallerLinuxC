#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

int main(){
	char data = 'a';
	int dt = data;
	string dd = "Num is: "+  to_string(dt);
	cout << dd << endl;
	return 0;
}
