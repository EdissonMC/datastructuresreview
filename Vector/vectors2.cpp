#include <iostream>     // for cout, cin
#include <utility>      // for pair
#include <tuple>        // for tuple
#include <array>        // for array
#include <vector>       // for vector
#include <fstream>      // for ifstream
#include <sstream>      // for istringstream
#include <iomanip>      // for setprecision

/*

    ESTE PROGRAMA MUESTRA COMO INICIALIZAR VECTORES 
    Y TAMBIEN MUESTRA COMO USAR UN TEMPLATE PARA UNA FUNCION
    LINK EJEMPLO:
    https://github.com/averyw09521/CS106L-spr20/blob/master/lectures/L3-references/init/main.cpp
    
*/





// forward declarations
template <typename T> void print_vector(const std::vector<T>& vec);


void creatingVectors() {
    // Uniform initialization
    std::cout << "\n\n Testing out the cool constructors using uniform initialization\n";
   
   
    // CREAMOS VECTOR 1
    std::vector<std::string> default_init;

    // CREAMOS VECTOR 2
    std::vector<std::string>  vec(10, "Ito-En");

    // CREAMOS VECTOR 3
    std::vector<std::string>  value_init{};

    // CREAMOS VECTOR 4
    std::vector<std::string>  direct_init{3, "init"};

    // CREAMOS VECTOR 5
    std::vector<std::string>  copy_init = {3, "init"};

    // CREAMOS VECTOR 6
    std::vector<std::string>  list_init{"1", "2", "3"};

    // CREAMOS VECTOR 7
    std::vector<std::string>  aggr_init = {"1", "2", "3"};


    std::cout << "\n-   -   -   -  -   -   -   -  -   -   -   -\n";
    print_vector(default_init);
    print_vector(vec);
    print_vector(value_init);
    print_vector(direct_init);
    print_vector(copy_init);
    print_vector(list_init);
    print_vector(aggr_init);


    std::cout << "\n-   -   -   -  -   -   -   -  -   -   -   -\n";
    std::cout << "\nCareful about ambiguous uniform initialization vs. initializer_list\n\n";
    std::vector<int> int_list_init{3, 2}; // {3, 2}
    std::vector<int> int_fill_ctor(3, 2); // {2, 2, 2}
    // auto list_init{3, 2};          // just found out this doesn't compile anymore, neat! 
    print_vector(int_list_init);
    print_vector(int_fill_ctor);

} // End creatingVectors


void fillVectorUsingIterations () {

    /* CREANDO UN VECTOR CON NUMEROS DIFERENTES */
    std::vector<int> myVector{20,30,40,50,60,70};
    
    std::cout << "MOSTRANDO EL VECTOR ORIGNAL"; 

    print_vector(myVector);


    /* 
    
        RELLENADO EL VECTOR CON SOLO NUMOEROS 100
        USANDO DEREFERENCIAMIENTO 
    
    */
    for (std::vector<int>::iterator itr = myVector.begin(); 
                itr != myVector.end(); 
                ++itr)
    {   
        *itr = 100;
    }




    std::cout << "MOSTRANDO EL VECTOR CON SOLO NUMEROS 100"; 
    print_vector(myVector);
}


/*
    
    ESTA FUNCION USA EL OPERADOR -> PARA PODER ACCEDER A UNA FUNCION DE 
    CADA ITEM EN EL VECTOR, USANDO ITERADORES Y USANDO ITERADORES MOSTRAR LA LONGITUD DE CADA PALABRA

*/

void usingFunctionsOfItemsInVector() {

    std::vector<std::string> myVector {"fresa", "mora","mango","banano", "manzana","papaya"};

    for (std::vector<std::string> ::iterator  itr= myVector.begin();
            itr!=myVector.end();
            ++itr)
    {
        
        std::cout << *itr << " \nlongitud de la palabra:  "<<itr->length() << std::endl;
    }

}




int main() {
    
    //fillVectorUsingIterations();
    usingFunctionsOfItemsInVector();
}



// bonus stuff to make it easier to test your results
// don't worry about any of the below






// generic function to print any kind of vector
template <typename T>
void print_vector(const std::vector<T>& vec) {

    std::cout << "{";
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter;
        if (iter + 1 != vec.end()) std::cout << ", ";
    }
    std::cout << "}\n";


}