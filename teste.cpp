#include <iostream>
#include "config.cpp"
// using namespace std;

int main(){
	config::ConfigReader cr("config.conf");
    std::cout << cr.getPacman(true) << std::endl;
	return 0;
}
