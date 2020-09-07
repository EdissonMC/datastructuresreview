#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string> 
#include <set>
#include <unordered_set>

template<typename T> 
void print_queue(T& q) {

    while(!q.empty()) {
        
        std::vector <std::string> myVector= q.top();
        q.pop();

         std::cout<< "{ ";
           for(std::vector <std::string>::iterator itr = myVector.begin();
                            itr != myVector.end() ;
                            ++itr){
                            
                          std::cout <<*itr<<" ";

            }
            std::cout<< " }\n";
    }

    std::cout << '\n';

}




int main () {

      // Using lambda to compare elements.
    // auto cmp = [](int left, int right) { 
    //     //std::cout <<left << ":" <<right <<std::endl;
    //     return (left ) > (right ); //^ 1
    // };

    //  std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    // for(int n : {1,8,5,6,3,4,0,9,7,2})
    //     q3.push(n);

    // std::cout  <<  q3.top()  <<  std::endl ;
    
    // std::cout << "---------\n";
    // print_queue(q3);


    /* PRIORITY QUEUE PARA STRINGS */

    std::vector <std::string> vectorTarget {"carro", "bus", "moto"};

    /* FUNCION DE COMPARACION */
    auto compareFn = [&vectorTarget] ( std::vector <std::string> vector1 ,  std::vector <std::string> vector2 ) {
      //  std::cout << "hello lambda" <<std::endl;

        std::vector <std::string>::iterator  itrStartVector1  =  vector1.begin();
        std::vector <std::string>::iterator  itrEndVector1    =  vector1.end();

        int counterLinksVector1=0;

         /* 1- COMPARA LOS LINKS VECTOR1  CON EL LINK TARGET */

            while (itrStartVector1 != itrEndVector1) {

               // std::cout << *itrStartLinks<<std::endl;

                    for(std::vector <std::string>::iterator itrTarget = vectorTarget.begin();
                            itrTarget != vectorTarget.end() ;
                            ++itrTarget){
                            
                           if(*itrStartVector1 == *itrTarget)  {
                                counterLinksVector1++;
                           }

                    }
               

               ++itrStartVector1;
            }

        /* 1- FIN DE LA COMPARACION DE LINKS */



         /* 2- COMPARA LOS LINKS VECTOR2  CON EL LINK TARGET */
             std::vector <std::string>::iterator  itrStartVector2  =  vector2.begin();
            std::vector <std::string>::iterator  itrEndVector2    =  vector2.end();

            int counterLinksVector2=0;
            while (itrStartVector2 != itrEndVector2) {

               // std::cout << *itrStartLinks<<std::endl;

                    for(std::vector <std::string>::iterator itrTarget = vectorTarget.begin();
                            itrTarget != vectorTarget.end() ;
                            ++itrTarget){
                            
                           if(*itrStartVector2 == *itrTarget)  {
                                counterLinksVector2++;
                           }

                    }
               
                ++itrStartVector2;
               
            }

        /* 2- FIN DE LA COMPARACION DE LINKS */

         return (counterLinksVector1 ) < ( counterLinksVector2 ); 
    }; /* FIN DE LA FUNCION DE COMPARACION*/







    /* CREAMOS LA PRIORITY QUEUE */
    std::priority_queue< std::vector<std::string>,
                         std::vector< std::vector<std::string> >,
                         decltype(compareFn)  >     ladderQueue(compareFn);

    /* RELLENAMOS LA PRIORITY QUEUE */
    //for(int n : {1,8,5,6,3,4,0,9,7,2}){
    //}

    std::vector <std::string> vectorLinks1 {"link1", "link2", "link3", "link3", "link3"};
    ladderQueue.push(vectorLinks1);
    
    std::vector <std::string> vectorLinks2 {"link1", "bus", "link3"};
    ladderQueue.push(vectorLinks2);
    
    std::vector <std::string> vectorLinks3 {"auto", "carro", "link3", "bus"};
    ladderQueue.push(vectorLinks3);
    
    std::vector <std::string> vectorLinks4 {"link1", "link2", "link3", "link3"};
    ladderQueue.push(vectorLinks4);
    
    std::vector <std::string> vectorLinks5 {"carro", "link2", "link3", "link3", "link3", "link3"};
    ladderQueue.push(vectorLinks5);
    
    print_queue(ladderQueue);
    
   

    return 0;
}