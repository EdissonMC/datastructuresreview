#include <iostream>
#include <set>
#include <string>

template <typename T> void print_set(const std::set<T>& mySet);

/*

    GENERANDO NUMEROS ALEATORIOS ASIGNANDOLOS A UN SET
    Y LUEGO USANDO ITERADORES PARA RECORRER EL SET Y 
    MOSTRARLOS POR CONSOLA, USANDO DEREFENCIAMIENTO

*/

void generateRandomNumbers() {

    //srand(static_cast<unsigned>(time(NULL)));
    std::set<int> randomNumbers;

    /* GENERA 10 NUMEROS ALEATORIOS */
    for(size_t k=0 ;  k<10; ++k) {
        randomNumbers.insert(rand()%20);
    }



    /* 
        
        IMPRIME ESTOS NUMEROS ALEATORIOS ALMACENADOS EN EL set, USANDO UN ITERADOR 
        POR DEFECTO EL SET SIEMPRE LOS ORGANIZA DE MENOR A MAYOR Y ASI LOS MOSTRARA

    */
    for (std::set<int>::iterator itr = randomNumbers.begin();  
                            itr!= randomNumbers.end(); 
                            ++itr)
    {

        std::cout << *itr << std::endl;

    }

}


/*
    
    ESTA FUNCION USA EL OPERADOR -> PARA PODER ACCEDER A UNA FUNCION DE 
    CADA ITEM EN EL SET, Y USANDO ITERADORES MOSTRAR LA LONGITUD DE CADA PALABRA

*/


void usingFunctionsOfItemsInSet() {

    std::set<std::string> mySet;
    
    mySet.insert ("fresa");

    mySet.insert ("mora");
    mySet.insert ("mango");
    mySet.insert ("banano");
    mySet.insert ("manzana");
    mySet.insert ("papaya");

    for (std::set<std::string> ::iterator  itr= mySet.begin();
            itr!=mySet.end();
            ++itr)
    {
        
        std::cout << *itr << " \nlongitud de la palabra:  "<<itr->length() << std::endl;
    }

}


/*

    ESTA FUNCION RETORNA UN LOTE DE DATOS ESPECIFICADOS DENTRO 
    DE UN LIMITE SUPERIOR Y UNO INFERIOR.

*/



void usingBoundsInSet() {

    std::set<int> mySet;
    
    mySet.insert (20);
    mySet.insert (34);
    mySet.insert (15);
    mySet.insert (250);
    mySet.insert (130);
    mySet.insert (100);
    mySet.insert (89);
    mySet.insert (265);
    mySet.insert (124);
    mySet.insert (340);
    mySet.insert (189);
    mySet.insert (276);
    mySet.insert (234);
    mySet.insert (320);

     std::cout << "\n\n IMPRIMIENDO TODOS LOS ITEMS \n \n";

    // IMPRIMIENDO TODOS LOS ITEMS SIN LIMITES
    for (std::set<int> ::iterator  itr= mySet.begin();
            itr!=mySet.end();
            ++itr)
    {
        
        std::cout << *itr << std::endl;
    }


    std::cout << "\n\n IMPRIMIENDO DENTRO DE LOS LIMITES \n \n";

     // IMPRIMIENDO  LOS ITEMS CON LIMITES
     std::set<int> ::iterator limiteInferior = mySet.lower_bound(33);
     std::set<int> ::iterator limiteSuperior= mySet.upper_bound(101);
     
    for (std::set<int> ::iterator  itr= limiteInferior ;
            itr != limiteSuperior ;
            ++itr)
    {
        
        std::cout << *itr << std::endl;
    }
}










void fillSetUsingIterations () {

    /* CREANDO UN VECTOR CON NUMEROS DIFERENTES */
    std::set<int> mySet{20,30,40,50,60,70};
    
    std::cout << "MOSTRANDO EL SET ORIGNAL"; 

    print_set(mySet);


    /* 
    
        RELLENADO EL VECTOR CON SOLO NUMOEROS 100
        USANDO DEREFERENCIAMIENTO 
    
    */
    // for (std::set<int>::iterator itr = mySet.begin(); 
    //             itr != mySet.end(); 
    //             ++itr)
    // {   
    //     *itr = 100;
    // }




    std::cout << "\nMOSTRANDO EL SET CON SOLO NUMEROS 100 \n \n"; 
    print_set(mySet);
}







void basicOperationsOnSets()
{

    std::set<int> mySet;
    
    mySet.insert (1);
    mySet.insert (2);
    mySet.insert (3);
    mySet.insert (4);
     mySet.insert (15);
    mySet.insert (5);
    mySet.insert (6);
    mySet.insert (7);
    mySet.insert (14);
    mySet.insert (8);


    std::cout << "\n\n IMPRIMIENDO TODOS LOS ITEMS \n \n";

    // IMPRIMIENDO TODOS LOS ITEMS SIN LIMITES
    for (std::set<int> ::iterator  itr= mySet.begin();
            itr!=mySet.end();
            ++itr)
    {
        
        std::cout << *itr << std::endl;
    }

    mySet.erase(14);
    mySet.erase(15);
     std::cout << "\n\n IMPRIMIENDO LOS ITEMS DESPUES DE BORRAR EL NUMERO 14 Y 15 \n \n";

    // IMPRIMIENDO TODOS LOS ITEMS SIN LIMITES
    for (std::set<int> ::iterator  itr= mySet.begin();
            itr!=mySet.end();
            ++itr)
    {
        
        std::cout << *itr << std::endl;
    }

    // VERIFICANDO SI UN DATO EXISTE
     std::cout << "\nPREGUNTANDO SI EL SET CONTIENE EL NUMERO 4 \n";
    if(mySet.count(7)) {
         std::cout << "Si lo contiene..\n";
    }

    // BUSCANDO UN NUMERO DENTRO DEL SET Y CAMBIANDO POR OTRO 
    std::cout << "\n BUSCANDO EL NUMERO 4 DENTRO DEL SET Y CAMBIANDO POR 444 \n";
    if(mySet.count(4)) {

        // std::set<int>::iterator datoAcambiar= mySet.begin();
        
        // *datoAcambiar =444;

         std::cout << "Si lo contiene..\n";
    }

}





int main() {

    //generateRandomNumbers();
    //usingFunctionsOfItemsInSet();
    //usingBoundsInSet();
    //    basicOperationsOnSets();
    fillSetUsingIterations();
    return 0;
}






// generic function to print any kind of vector
template <typename T>
void print_set(const std::set<T>& mySet) {

    std::cout << "{";
    for (auto iter = mySet.begin();  iter != mySet.end();  ++iter) {
        std::cout << *iter << " ";

       // if (iter + 1 != mySet.end()) std::cout << ", ";
    }
    std::cout << "}\n";


}