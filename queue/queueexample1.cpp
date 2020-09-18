#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>

void showq(std::queue <int> gq) 
{ 
    std::queue <int> g = gq; 
    while (!g.empty()) 
    { 
        std::cout << '\t' << g.front(); 
        g.pop(); 
    } 
    std::cout << '\n'; 
} 


void showqueueString(std::queue < std::vector<std::string> > gq) 
{ 
    std::queue < std::vector<std::string> >  g = gq; 
    while (!g.empty()) 
    { 
        std::cout << " [ ";
        std::vector<std::string > tmpVector= g.front();
        for(auto itr = tmpVector.begin(); itr<tmpVector.end(); itr++){
             std::cout << *itr << ',' ; 
        }
        std::cout << " ] " ;//<< '\t'

        g.pop(); 
    } 
    std::cout << '\n'; 
} 



void ejemplo1() {
     std::queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    std::cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    std::cout << "\ngquiz.size() : " << gquiz.size(); 
    std::cout << "\ngquiz.front() : " << gquiz.front(); 
    std::cout << "\ngquiz.back() : " << gquiz.back(); 
  
    std::cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
      std::cout << "\nafter make pop() function : "; 
    showq(gquiz);
}




void ejemplo2(){
    std::queue< std::vector<std::string> > queueLadders;

    // ADDING A VECTOR TO A QUEUE
        std::vector<std::string> vector1{"cato", "pato"};
        queueLadders.push(vector1);

    // ADDING A VECTOR TO A QUEUE
        std::vector<std::string> vector2{"lapiz", "lata"};
        queueLadders.push(vector2);

    //  SHOWING ON SCREEN THE QUEUE
        showqueueString(queueLadders);

}



int main () {
     
   
   // ejemplo1();
   ejemplo2();

    return 0;
}