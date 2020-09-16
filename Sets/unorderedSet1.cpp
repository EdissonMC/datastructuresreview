#include<iostream>
#include<unordered_set>
#include <string>
#include <vector>



int main () {
    std::unordered_set<std::string> queryLinks;

    queryLinks.insert("prueba");

    std::vector<std::string> vectorConverter;

   // copy(queryLinks.begin(), queryLinks.end(), myVector.begin());
     
      for ( std::unordered_set<std::string>::iterator  it = queryLinks.begin();
                 it != queryLinks.end(); ++it) 
        {
            vectorConverter.push_back(*it);
        }


      for (std::vector<std::string>::iterator itrVec = vectorConverter.begin() ;
                   itrVec != vectorConverter.end() ;
                   ++itrVec)
        {
            std::cout<< *itrVec;
        }


    return 0;
}