#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>


/**
 * This program looks up a three-letter airport code
 * in Map object
 * 
*/
void readCodes(std::string &fileName ,std::map<std::string, std::string> &map);
std::string upperCase(std::string &line);

int main(){

     std::map<std::string, std::string> mapCodes;
     std::string fileName="airportcodes.txt";
     readCodes(fileName, mapCodes);

    // mapCodes["BKK"]
    std::string codigo ="BKK";
    // std::cout << "code bkk  " <<mapCodes[codigo];

    std::string requestCode="";
    std::string result="";
    while (true) {
         std::cout <<"\nEnter the code :> "  ;
        getline(std::cin, requestCode);
        requestCode =  upperCase (requestCode);

        result= mapCodes[requestCode];
        if(result!=""){
            std::cout <<"R:/ " << requestCode <<" : " << result <<"\n";
        } else{
             std::cout <<"-Enter valid code- \n";
        }
        
    }
    return 0;
}


void readCodes(std::string &fileName ,std::map<std::string, std::string> &mapCodes) {
    
    std::ifstream streamFile;
    streamFile.open(fileName.c_str());

    if(streamFile.fail() ){
        std::cout << "error reading the file";
    }

    std::string line;
    while(getline(streamFile, line)) {
        std::cout<< line.substr(0,3) << "\n";
         mapCodes[line.substr(0,3)] = line.substr(4);
    }
   
}

std::string upperCase(std::string &line){
  
    for(std::string::size_type i=0; i<line.length(); i++){
        line[i] = std::toupper(line[i]);
    }
    return line;
}