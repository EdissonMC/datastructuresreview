#include <iostream>
#include <string>
#include <map>



void ejemplo2BusquedasYAsignaciones() {
    
    /* CREAMOS EN MAP*/
    std::map< std::string , int > numberMap;
    

    /* RELLENAMOS EL MAP */
    numberMap["zero"] =0;
    numberMap["one"] =1;
    numberMap["two"] =2;

    std::cout <<"\n-> EJEMPLO 2 BUSQUEDAS Y ASIGNACIONES \n";

    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP ORIGINAL \n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }
    

    /* BUSCA EN EL MAP UNA KEY ESPECIFICA y CHEQUEA SI EL VALOR EXISTE O NO*/
    std::cout <<"\n-> Buscamos en el map la key= XYZ \n";
    std::map< std::string, int>::iterator itr =  numberMap.find("XYZ") ;// numberMap.find("xyz");
    
    if (itr == numberMap.end()) { // NO EXISTE
        std::cout << "\nKey XYZ does not exist." << std::endl; 
    } else                        // SI EXISTE
    {
      std::cout << "Key " << itr->first << " has value " << itr->second << std::endl;
    }


    /* BUSCA EN EL MAP UNA KEY ESPECIFICA */
    /* Y CHEQUEA SI EL VALOR EXISTE Y SINO EXISTE LO CONSTRUYE*/
    std::cout <<"\n-> Buscamos en el map la key= one \n";
    std::map< std::string, int>::iterator itr2 =  numberMap.find("nine") ;// numberMap.find("xyz");
    
    if (itr2 == numberMap.end()) { // NO EXISTE , LO ASIGNA
          numberMap["nine"] =9;
    } else                        // SI EXISTE
    {
        std::cout << "Key " << itr->first << " has value " << itr->second << std::endl;
    }





    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP DESPUES ASIGNAR EL 'ninee' \n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }
    

    /* HACIENDO ASIGNACIOES MEDIANTE EL USO DE PAIRS */
    std::cout <<"\n->INSERTANDO DATOS 6,7,10 USANDO EL PAIR \n";
    numberMap.insert(std::make_pair("six",   6)); 
    numberMap.insert(std::make_pair("seven", 7)); 
    numberMap.insert(std::make_pair("ten",  10));



    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP DESPUES ASIGNAR DATOS MEDIANTE EL USO DE PAIR \n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }

    /* Populate a map using [ ] */ 
    // map<string, string> one; 
    numberMap["C++"] = 17; 
    numberMap["C++"] = 18;

    
    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP DESPUES ASIGNAR DATOS MEDIANTE EL USO DE PAIR \n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }

    /* Populate a map using insert */ 
    std::cout << "\n->USANDO insert y pairs PARA AGREGAR DATOS \n";
    std::pair<  std::map< std::string , int>::iterator, bool > result1 =  numberMap.insert(std::make_pair("C", 29)); 
    std::pair<  std::map< std::string , int>::iterator, bool > result2 =  numberMap.insert(std::make_pair("C", 30));
    std::cout <<"\n Insertar 'C:29' ? "  << " : "  << result1.second;
    std::cout <<"\n Insertar 'C:30' ? "  << " : "  << result2.second;
    /* If insertion failed, manually set the value. */
    if(!result2.second) {
       std::cout<< "\nInsertion 30 Manual, using results";
        result1.first->second = 30;
    }

     /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP DESPUES ASIGNAR DATOS MEDIANTE EL USO DE PAIR \n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }

    numberMap.clear();
      /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\n-> EL CONTENIDO DEL MAP DESPUES DE USAR CLEAR ....\n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }

} // END ejemplo2BusquedasYAsignaciones








void basicOperations() {

    /* CREANDO EL MAP*/
    std::map< std::string , int > numberMap;

    /* RELLENANDO EL MAP CON DATOS */
    numberMap["zero"] =0;
    numberMap["one"] =1;
    numberMap["two"] =2;
    numberMap["five"] =5;



    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\nMOSTRANDO TODO EL CONTENIDO DEL MAP \n";

    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }



    /* ACCEDIENDO AL MAP MEDIANTE keys Y MOSTRANDOLOS POR CONSOLA*/

    std::cout <<"\nvalor en la posicion zero del map : " << numberMap["zero"] << std::endl;

    std::cout <<"\nvalor en la posicion two del map : "  << numberMap["two"] << std::endl;

    std::cout <<"\nvalor en la posicion two del map multiplicada por si misma : "  << numberMap["two"]  * numberMap["two"] << std::endl;




    /* BORRANDO DATOS EN EL MA */
    numberMap.erase ("five");




    /* USANDO UN FOR Y ITERADORES PARA MOSTRAR EL CONTENIDO DEL MAP */
    std::cout <<"\nEL CONTENIDO DEL MAP DESPUES DE BORRAR EL DATO 'five'\n";    
    for (std::map <std::string, int>::iterator itr = numberMap.begin(); 
        itr != numberMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }

}

void printMap() {
        
    std::map< std::string , int > myMap;
    myMap["zero"] =0;
    myMap["one"] =1;
    myMap["two"] =2;


    for (std::map <std::string, int>::iterator itr = myMap.begin(); 
        itr != myMap.end(); ++itr) 
    {
         std::cout << itr->first << ": " << itr->second << std::endl;
    }
        
       

}


// template <typename T>
// void printMapGeneric(const std::map<T> & myMap) {
    
    
//     for (std::map <std::string, int>::iterator itr = myMap.begin(); 
//         itr != myMap.end(); 
//         ++itr) 
//     {
//          std::cout << itr->first << " : " << itr->second << std::endl;
//     }
      

// }



int main(){

   //basicOperations();

    ejemplo2BusquedasYAsignaciones();

    // printMap();

}


