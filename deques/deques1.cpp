#include <iostream>
#include <deque>
#include <string>


template <typename T> void printDeque (const std::deque<T> fila );


int main () {
    // CREAMOS UNA DEQUE
    std::deque<int> fila1 {10,11,12,13} ;

    // IMPRIMIMOS UNA DEQUE
    std::cout<< "\n * Fila Original: " ;
    printDeque (fila1);

    // AGREGAMOS UN DATO AL FRENTE
    std::cout<< "\n * anadiendo un valor 9 en el frente : " <<std::endl;
    fila1.push_front(9);

    // IMPRIMIMOS UNA DEQUE
    std::cout<< "\n   resultado : " ;
    printDeque (fila1);

    // AGREGAMOS UN DATO ATRAS
    std::cout<< "\n * anadiendo el valor 14 en la cola : " <<std::endl; 
    fila1.push_back(14);

    
    // IMPRIMIMOS UNA DEQUE
    std::cout<< "\n   resultado : " ;
    printDeque (fila1);


    // MOSTRAMOS EL VALOR QUE ESTA EN EL FRENTE
    std::cout<< "\n * valor en el frente : " << fila1.front() << std::endl;

    // MOSTRAMOS EL VALOR QUE ESTA EN EL BACK
    std::cout<< "\n * valor en la cola : " <<fila1.back() << std::endl;

    return 0;
}


template <typename T>
void printDeque (const std::deque<T> myDeque ) {

     //for (int index; index< fila.size() ;index++) {
        // std::cout << fila[indes] ;
    for (auto index = myDeque.begin();    index != myDeque.end() ;     ++index ){ 
        
        std::cout << *index << " ";
    }
    std::cout << std::endl;
}