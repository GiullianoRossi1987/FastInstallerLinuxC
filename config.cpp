#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace config{
    class ConfigReader{
        protected:
            std::string config_file;
            bool gotFile = false;
            struct ConfigData{
                std::string dft_pacman;
                bool useGUI;
            };
            ConfigData data;


            void readFile(){
                if(this->gotFile){
                    std::fstream fl;
                    fl.open(this->config_file);
                    // std::vector<std::string> linesB;
                    ConfigReader::ConfigData newEntrance;
                    std::string lineB;
                    while(getline(fl, lineB)){
                        std::string sp_equal = lineB.substr(0, lineB.find_first_of("="));
                        std::string sp_val   = lineB.substr(lineB.find_first_of("=")+1);
                        if(sp_equal == "DFT_PACMAN"){
                            newEntrance.dft_pacman = sp_val;
                            continue;
                        }
                        if(sp_equal == "START_ON_GUI"){
                            newEntrance.useGUI = sp_val == "true";
                        }
                    }
                    this->data = newEntrance;
                }
            }
        public:

            ConfigReader(std::string file){
                this->config_file = file;
                this->gotFile = true;
                readFile();
            }

            std::string getPacman(const bool& no_quotes = false){

                return no_quotes ? this->data.dft_pacman.substr(
                    this->data.dft_pacman.find_first_not_of("\""), 
                    this->data.dft_pacman.find_last_not_of("\"")
                ) : this->data.dft_pacman;
            }

            bool getUseGUI(){ return this->data.useGUI; }
    };
}
