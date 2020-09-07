#include <functional>
#include <queue>
#include <vector>
#include <iostream>
 

template<typename T> 
void print_queue(T& q) {

 

   
     
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }

    std::cout << '\n';

}

int main () {

      // Using lambda to compare elements.
    auto cmp = [](int left, int right) { 
        //std::cout <<left << ":" <<right <<std::endl;
        return (left ) > (right ); //^ 1
    };

    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2}){

        q3.push(n);
        // std::cout << "-------------\n";
        
    }
        

    // print_queue(q3);

    std::cout  <<  q3.top()  <<  std::endl ;
    
    std::cout << "----ORGANIZACION FINAL-----\n";
    print_queue(q3);
    return 0;
}