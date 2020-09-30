#include <iostream>


/*

    ESTE PROGRAMA MUESTRA LA IMPLEMENTACION SUPER BASICA DE UNA LINKEDLIST

*/
struct node
{
   int data;
   node * next_node;

};

void showBst(node& nodeHead ) {


    node *nodeTracking = &nodeHead;

    std::cout << "Node data " << (*nodeTracking).data <<std::endl; 
    // std::cout << (*nodeTracking).next_node <<std::endl; 
        
    while ( (*nodeTracking).next_node != NULL ) {
        
         nodeTracking = (*nodeTracking).next_node;
        std::cout << "Node data "<< (*nodeTracking).data <<std::endl; 
       
    }
}




int main () {

    // CREAMOS EL NODO RAIZ
    node head;

    // AGREGAMOS INFORMATION ALEATORIA
    head.data = 1;
    head.next_node =NULL;

    // CREAMOS OTRO NODO Y SE LO ANADIMOS MANUALMENTE AL NODO ROOT
    node body1;
    body1.data = 2;
    body1.next_node = NULL;
    head.next_node = &body1;

    // CREAMOS OTRO NODO Y SE LO ANADIMOS MANUALMENTE AL NODO ROOT
    node body2;
    body2.data = 3;
    body2.next_node = NULL;
    body1.next_node = &body2;

    // MOSTRAMOS POR PANTALLA LOS NODOS QUE TIENE LA CADENA
    showBst(head);




}