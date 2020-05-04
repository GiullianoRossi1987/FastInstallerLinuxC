#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <string>
#include <unistd.h>
#define LOG_DELIMITER "   "

namespace database_logs{
    class LogsSystem{
        private:
            std::string logs_file;
            bool got_logs = false;
        public:
            
            void load(std::string file){
                logs_file = file;
                got_logs = true;
            }
            
            void unload(){
                if(got_logs){
                    logs_file = "";
                    got_logs = false;
                }
            }
            
            std::string getLogs(){ return logs_file;}
            bool getGot(){ return got_logs;}
            
            str::string read(){
                if(got_logs){
                    std::string data;
                    std::ofstream handler;
                    handler.open(logs_file);
                    std::string tmp_line;
                    while(std::getline(handler, tmp_line))
                        data += tmp_line;
                    return data;
                }
                else std::cerr << "Logs file not loaded error!";
            }
            
            void addLog(std::string action, bool success = true){
                if(got_logs){
                    int pid = std::fork();
                    int i_success = success ? 1 : 0;  // maybe i will trade this for (int)success
                    if(pid == 0){
                        std::string log = std::to_string(getpid()) + LOG_DELIMITER + action + LOG_DELIMITER + std::to_string(i_success);
                        std::fstream handler;
                        handler.open(logs_file, std::ios::app);
                        handler << log;
                        handler.close();
                    }
                }
            }
        }
    };
}

namespace database_sql{
    class Database{
        private:
            std::sqlite3 *database = NULL;
            bool got_database_open = false;
            std::string file_database = "";
        public:
            
            void connect(std::string file_path){
                int rc;
                char *zErrMsg = 0;
                rc = std::sqlite3_open(file_path, &database);
                if(rc != 0){
                    std::cerr << "Can't connect to database! ERROR " + std::to_string(std::sqlite3_errmsg(database));
                }
                else{
                    got_database_open = true;
                    file_database = file_path;
                }
            }
            
            void disconnect(){
                if(got_database_open) std::sqlite3_close(database);
            }
            
            std::sqlite3* getDatabase(){ return database;}
            
            std::string getFileDB(){ return file_database;}
    };
    
    class DebianPackages: public Database{
        private:
            bool packExists(std::string pack){
                if(got_database_open){
                    char *sql;
                    sql = "SELECT ";
                    char *zErrMsg = 0;
                    int rc;
                    rc = std::sqlite3_exec(database, )
    };
}
