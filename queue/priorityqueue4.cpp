#include <iostream>
#include <queue>
#include <vector>

#include<cctype>


void showVector(std::vector<std::string > &vec);

void compararLastWord();


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




int main() {


        std::string wordTarget= "palo";

    //  USING LAMBDA TO COMPARE TWO VECTORES.
        auto cmp = [wordTarget] ( std::vector<std::string>  vectorLeft, std::vector<std::string>  vectorRight) { 


                //  std::vector<std::string> vector1{"cato", "pato"};
                auto itr1 = vectorLeft.end() - 1;
                std::string word1 = *itr1;

                // std::vector<std::string> vector2{"cato", "palo"};
                auto itr2 = vectorRight.end() - 1;
                std::string word2 = *itr2;

                


                int contadorLeft=0;
                for (int i =0 ; i < word1.length(); i++) {
                    if(word1[i] == wordTarget[i]) {
                        contadorLeft++;
                    }
                }

                int contadorRight=0;
                for (int i =0 ; i < word2.length(); i++) {
                    if(word2[i] == wordTarget[i]) {
                        contadorRight++;
                    }
                }

                std::cout <<"contadorLeft = "<<contadorLeft <<"  contadorRight = " << contadorRight  << "\n";

                return (contadorLeft ) < (contadorRight ); //^ 1

        };

        // std::priority_queue<std::string , std::vector<std::string>, decltype(cmp)>  queueVectors(cmp);
    
    /* CREAMOS LA PRIORITY QUEUE */
        std::priority_queue< std::vector<std::string>,
                            std::vector< std::vector<std::string> >,
                            decltype(cmp)  >     queueVectors(cmp);

   
    // ADDING A VECTOR TO A QUEUE
        std::vector<std::string> vector2{"lapiz", "lata"};
        queueVectors.push(vector2);

     // ADDING A VECTOR TO A QUEUE
        std::vector<std::string> vector1{"cato", "pato"};
        queueVectors.push(vector1);

    // ADDING A VECTOR TO A QUEUE
        std::vector<std::string> vector3{"carro", "tato"};
        queueVectors.push(vector3);

    //  SHOWING ON SCREEN THE QUEUE
        //print_queue(queueVectors);
         

}


void compararLastWord() {

        std::string wordTarget= "palo";
    
    
        std::vector<std::string> vector1{"cato", "pato"};
        auto itr1 = vector1.end() - 1;
        std::string word1 = *itr1;

        std::vector<std::string> vector2{"cato", "palo"};
        auto itr2 = vector2.end() - 1;
        std::string word2 = *itr2;

        

        int contadorLeft=0;
        for (int i =0 ; i < word1.length(); i++) {
        if(word1[i] == wordTarget[i]) {
            contadorLeft++;
        }
        }

        int contadorRight=0;
        for (int i =0 ; i < word2.length(); i++) {
        if(word2[i] == wordTarget[i]) {
            contadorRight++;
        }
        }

        std::cout <<"contadorLeft = "<<contadorLeft <<"  contadorRight = " << contadorRight  << "\n";

}

void showVector(std::vector<std::string > &vec) {

     std::cout << "\n\n Tamano del vector " << vec.size()  << "\n ";

                std::cout << "[ ";

                for(auto itr = vec.begin();  itr<vec.end();  itr++) {
                    std::cout << *itr << ',' ; 
                }

                std::cout << " ] " ;//<< '\t'

}