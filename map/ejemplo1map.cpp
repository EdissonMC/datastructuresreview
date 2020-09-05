#include <iostream>
#include <string>
#include <map>
#include <sstream>


std::string GetLine() {
    std::string response;
    std::getline(std::cin, response);
    return response;
}


int main () {

    std::map<std::string, int>frecuencyMap;

    std::cout << "Enter words" << std::endl;

    while (true) {
        std::cout << "> ";
        std::string response = GetLine();
        if (response.empty()) break;

        std::istringstream stream(response);
        std::string word;
        
        while (stream >> word) {
            
            /*
                This single line is doing a ton of work. The square bracket notation for
                accessing  values in maps will return a reference to the value associated with
                the specified key.  We can then modify it with ++ directly.

                However,  if response is not already a key in the map, the square brackets 
                do a bit of extra work first. They automatically insert a new key-value pair 
                into the map, where the key is resopnse and the value is a reasonable default value
                in the case of integers, is 0.
            */
            ++frecuencyMap[word];
        }

        std::cout << "Enter words to look up. " << std::endl;
        while (true) {
            std::cout << "> ";
            std::string response = GetLine();

            if(response.empty()) break;
            
            /*
                Returns the number of keys equal to response.
                In anything but a multimap/multiset, this is either going to be 1 or 0.
            */

           if (frecuencyMap.count(response)) {
               std::cout << frecuencyMap[response] << "entries found" << std::endl;    
           }else {
               std::cout << "None" <<std::endl;
           }

        }

    }


    return 0;
}