#include <iostream>
#include <fstream>
#include <ofstream>
#include <string.h>
#define DELIMITER ";"
#define LINE_DELIMITER "\n"
#define MAX_FILE_NAME 420
#define MIN_FILE_NAME 5
using namespace std;

class DatabaseGen{
	protected:
		char fileDatabase[MAX_FILE_NAME];
		bool gotFile = false;
	public:
		void loadDatabase(char file[MAX_FILE_NAME]){
			memcpy(file[MAX_FILE_NAME], fileDatabase, sizeof(file));
			gotFile = true;
		}

		char *getContent(){
			if(!gotFile) throw "No database loaded";
			char data[];
			ofstream resource;
			resource.open(fileDatabase);
			resource >> data;
			
		}
};
