#include <iostream>   // for count,  cin
#include <utility>    // for pair
#include <tuple>      // for tuple
#include <array>      // for array
#include <vector>     // for vector
#include <fstream>    // for ifstream
#include <iomanip>    // for istringstream

void simple1 ();

void simple2 ();
void simple3 ();
void simple4Resizing ();
void simple5DeletingItem ();
void simple6InsertingItem () ;
void printVector (std::vector<int>& values);




int main () {

   // simple1 ();
   // simple2 ();

   // simple4Resizing();
    //simple5DeletingItem();

    simple6InsertingItem();
}

void simple1 () {
    // Creamos un vector
    std::vector <int> data = {1, 2, 3};
    // Agregamos un dato al vector
    data.push_back (12);
    // Mostramos el ultimo dato que tenga el vector por consola
    std::cout << data[data.size() - 1 ] << std::endl;   
    // Eliminamos el ultimo elemento que tenga el vector
    data.pop_back ();
    // Volvemos a mostrar por consola el tamano del vector en general
    std::cout << data.size() <<std::endl;

}

/*
    Inserta un dato en un vector
*/

void simple2 () {

    std::vector<int> values{1,2,4};

    // IMPRIMIENDO EN PANTALLA EL VECTOR
    for (size_t i = 0; i < values.size(); ++i)
        std::cout << values[i] << std::endl;


    std::cout << "\n insertando datos.... \n";

    // INSERTANDO EL NUMERO 3
    values.insert(values.begin() +2, 3);


    // IMPRIMIENDO EN PANTALLA DE NUEVO EL VECTOR
    printVector(values);
    // for (size_t i = 0; i < values.size(); ++i)
    //     std::cout << values[i] << std::endl;
    
}//end simple2








/*
    This programm generate 20 random numbers into a vector usting STL 
*/
void simple3 () {

    int kNumbInt = 20 ;

    // allocation memory for vector
    std::vector<int> vec(kNumbInt);

    // Generating random numbers
    std::generate(vec.begin(), vec.end(), rand);

    // Sorting from minimun to maximun
    std::sort(vec.begin(),  vec.end() );

    // Showing for console the numbers
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, "\n")) ;
    
    // Mostrar por consola version normal
    // for (int i=0; i< vec.size();i++) {
    //     std::cout<< i<< " |  "<< vec[i]<<std::endl;
    // }
    
    //std::sort(vec.ge)

}// end simple3




/*

    This programm show the resising feature

*/


void simple4Resizing() {
    std::vector<int> myVector;
    printVector(myVector);

    std::cout<< "\nresizing the vector 10 items ";
    myVector.resize(10);   // Grow the vector, setting new elements to 0
    printVector(myVector); // Output: 0 0 0 0 0 0 0 0 0 0

    std::cout<< "\nresizing the vector 5 items ";
    myVector.resize(5);   // Grow the vector, setting new elements to 0
    printVector(myVector); // Output: 0 0 0 0 0 0 0 0 0 0

    std::cout<< "\nresizing the vector 7 items with number 1 inicialization ";
    myVector.resize(7,1);   // Grow the vector, setting new elements to 0
    printVector(myVector); // Output: 0 0 0 0 0 0 0 0 0 0

    std::cout<< "\nresizing the vector 1 items with number 7 inicialization ";
    myVector.resize(1,7);   // Grow the vector, setting new elements to 0
    printVector(myVector); // Output: 0 0 0 0 0 0 0 0 0 0

}// end simple4


void simple5DeletingItem () {

    std::cout << "Original vector"<<std::endl;
    std::vector<int> myVector{1,2,3,4,5,6,7};
    printVector(myVector);

    
    std::cout << "\nDeleting last item in the vector, apply pop_back "<<std::endl;
    myVector.pop_back();
    printVector(myVector);


    std::cout << "\nDelete item 3 in the vector"<<std::endl;
    int index=2;
    myVector.erase (myVector.begin() + index);
    printVector(myVector);


    std::cout << "Delete all items "<<std::endl;
    myVector.clear();
    printVector(myVector);

  

}




void simple6InsertingItem () {
    std::cout << "Original vector"<<std::endl;
    std::vector<int> myVector{1,2,3,4,5,6,7};
    printVector(myVector);
    

     std::cout << "\nInserting 15 item at 5 position "<<std::endl;
    myVector.insert(myVector.begin() + 4, 15); 
    printVector(myVector);
    
    std::cout << "\nInserting 2 itmes of 33 value at the start of the vector  "<<std::endl;
    myVector.insert(myVector.begin() , 2, 33);
    printVector(myVector);

    std::cout << "\nInserting 3 itmes of 11 value at  7 index of the vector  "<<std::endl;
    myVector.insert(myVector.begin() +7, 3, 11);
    printVector(myVector);

      int inicio = myVector.back();
    std::cout << "inicio del vector \n" <<inicio<<std::endl;
}







void printVector (std::vector<int>& values) {
    // IMPRIMIENDO EN PANTALLA DE NUEVO EL VECTOR
   // std::cout<<"printing the vector"<<std::endl;
    std::cout<<std::endl;
    for (size_t i = 0; i < values.size(); ++i)
        std::cout << values[i] << "  ";
    std::cout<<std::endl;
}