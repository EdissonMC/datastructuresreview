// C++ program to illustrate 
// the vector::shrink_to_fit()  
#include <iostream>
#include <vector> 
using namespace std; 
  

template <typename T>
void shrinkCapacity(std::vector<T>& v)
{
    std::vector<T> tmp(v); // copy elements into a new vector
    v.swap(tmp); // swap internal vector data
}

/*

    ESTE PROGRAMA MUESTRA LAS PROPIEDADES DE SIZE, CAPACITY Y
    LA FUNCION shrink_to_fit() ANTES Y DESPUES DE SER APLICADA

*/


void analisis1 () {

       // Initialized vector con tamano de 10 elementos
    vector<int> v(10); 
    
    // RELLENAMOS CADA ELEMENTO CON UN VALOR
    for (int i = 0; i < 10; i++) 
        v[i] = i; 
  
    // MOSTRAMOS EL Initial vector size
    cout << "\n->Vector SIZE initially: " << v.size(); 
    cout << "\n->Vector CAPACITY initially: " << v.capacity(); 

    // MOSTRAMOS LOS ELEMENTOS QUE CONTIENE
    cout << "\n->Vector elements are: "; 
    for (int i = 0; i < 10; i++) 
        cout << v[i] << " "; 
  
    // REAJUSTAMOS EL TAMANO DEL VECTOR
    // changes the size of the Vector 
    // but does not destroys the elements 
    v.resize(5); 
    


    // MOSTRAMOS POR CONSOLA EL TAMANO
    cout << "\n\nVector SIZE after resize(5): " << v.size(); 
    cout << "\nVector CAPACITY after resize(5): " << v.capacity(); 
  


    // MOSTRAMOS LOS ELEMENTOS DESPUES DE REDIMENCIONAR
    cout << "\nVector elements after resize(5) are: "; 
    for (int i = 0; i < 10; i++) 
        cout << v[i] << " "; 


    // ENCOGEMOS LA CAPACIDAD DEL VECTOR
    // Shrinks to the size 
    // till which elements are 
    // destroys the elements after 5 
    v.shrink_to_fit(); 
  
    // MOSTRAMOS EL TAMANO DEL VECTOR DESPUES DE ENCOGERLO
    cout << "\n\n->Vector SIZE after shrink_to_fit(): " << v.size(); 
    cout << "\n->Vector CAPACITY after shrink_to_fit() " << v.capacity(); 
  
    // MOSTRAMOS LOS ELEMENTOS PRESENTES EN EL VECTOR DESPUES DE ENCOGERLO
    cout << "\n->Vector elements after shrink_to_fit() are: "; 
    for (int i = 0; i < 10; i++) 
        cout << v[i] << " "; 
  
}







void analisis2 (){

    // Initialized vector con tamano de 10 elementos
    vector<int> v(20); 
    
    // RELLENAMOS CADA ELEMENTO CON UN VALOR
    for (int i = 0; i < 10; i++) 
        v[i] = i; 
    
    // MOSTRAMOS LOS ELEMENTOS QUE CONTIENE
    cout << "\n->Vector elements are: "; 
    for (int i = 0; i < 10; i++) 
        cout << v[i] << " "; 
  
    // MOSTRAMOS POR CONSOLA EL TAMANO
    cout << "\n\nVector SIZE inicial : " << v.size(); 
    cout << "\nVector CAPACITY inicial: " << v.capacity(); 
    
    shrinkCapacity(v) ;

  
    // MOSTRAMOS LOS ELEMENTOS QUE CONTIENE
    cout << "\n\n\n->Vector elements after shrinkCapacity() are: "; 
    for (int i = 0; i < 10; i++) 
        cout << v[i] << " "; 
    
    // MOSTRAMOS POR CONSOLA EL TAMANO
    cout << "\n\nVector SIZE after shrinkCapacity() : " << v.size(); 
    cout << "\nVector CAPACITY after shrinkCapacity() : " << v.capacity(); 
    
}





int main() 
{ 
   //analisis1 ();
    analisis2();
    return 0; 
} 