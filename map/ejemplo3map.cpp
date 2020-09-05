#include <map>
#include <utility>
#include <iostream>
#include <string>


void mapIterators() {
    std::map <std::string,int> myMap;

    myMap.insert ( std::make_pair("manzanas", 2) );
    myMap.insert ( std::make_pair("banannos", 14) );
    myMap.insert ( std::make_pair("arandanos", 1) );
    myMap.insert ( std::make_pair("papaya", 3 ));
//	myMap.insert ( make_pair("STL", 137));
    for (auto thing : myMap) {
       std::cout << thing.first <<" : "<<thing.second  << std::endl;
    }

}

int main () {
    
    mapIterators() ;

    return 0;
}

