// #include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string> 
// #include <set>
// #include <unordered_set>
#include "point.h"
#include "prueba.h"

/*
  ESTE CODIGO USA UNA priorityQueue PARA ORGANIZAR OBJETOS TIPO node
  SEGUN LA DISTANCIA EUCLIDIANA ENTRE ELLOS Y CUANDO SE IMPRIME EL CONTENIDO SE 
  PUEDE VER DE LOS NODOS MAS CERCANOS A LOS MAS LEJANOS AL PUNTO ESPECIFICADO EN
  LA FUNCION LAMBDA. 

*/



  struct mynode
            {
                int data;
                //Point<N> dataPoint;
                Point<2> dataPoint;
                struct mynode *next;
                struct mynode *before;
                // ElemType classification;     
                std::string classification;     
            };


template<typename T> 
void print_queue(T& q) {
// void print_queue(T& q) {

    while(!q.empty()) {
        
        mynode myNode= q.top();
        q.pop();

         std::cout<< "{ ";
           for(int itr = 0;
                     itr < myNode.dataPoint.size() ;
                            ++itr){
                            
                          std::cout << myNode.dataPoint[itr] <<" ";

            }

            std::cout<< "|  " << myNode.classification << " }\n";
    }

    std::cout << '\n';

}


template<typename T> 
void rellenadorDePoints(T& classificationQueue) {

    mynode node1 ;
    node1.dataPoint [0] = 2;
    node1.dataPoint [1] = 3;
    node1.classification = "pera";

    classificationQueue.push(node1);
    

    
    mynode node2 ;
    node2.dataPoint [0] = 2;
    node2.dataPoint [1] = 4;
    node2.classification = "pera";

    classificationQueue.push(node2);


    mynode node3 ;
    node3.dataPoint [0] = 3;
    node3.dataPoint [1] = 4;
    node3.classification = "pera";
    classificationQueue.push(node3);

    mynode node4 ;
    node4.dataPoint [0] = 2;
    node4.dataPoint [1] = 5;
    node4.classification = "pera";
   classificationQueue.push(node4);


    mynode node5 ;
    node5.dataPoint [0] = 3;
    node5.dataPoint [1] = 5;
    node5.classification = "pera";
   classificationQueue.push(node5);

    mynode node6 ;
    node6.dataPoint [0] = 11;
    node6.dataPoint [1] = 1;
    node6.classification = "manzana";
   classificationQueue.push(node6);

    mynode node7 ;
    node7.dataPoint [0] = 10.5;
    node7.dataPoint [1] = 2.5;
    node7.classification = "manzana";
       classificationQueue.push(node7);


    mynode node8 ;
    node8.dataPoint [0] = 10;
    node8.dataPoint [1] = 1;
    node8.classification = "manzana";
       classificationQueue.push(node8);

    mynode node9 ;
    node9.dataPoint [0] = 12;
    node9.dataPoint [1] = 3;
    node9.classification = "manzana";
       classificationQueue.push(node9);


    mynode node10 ;
    node10.dataPoint [0] = 9.5;
    node10.dataPoint [1] = 2.5;
    node10.classification = "manzana";

    classificationQueue.push(node10);
}

int main () {

 


    /* PRIORITY QUEUE PARA STRINGS */

    // Point<2> pointTarget;
    // pointTarget [0]= 1;
    // pointTarget [1] =3;

    /* FUNCION DE COMPARACION */
    // auto compareFn = [&pointTarget] ( mynode node1 ,  mynode node2 ) {
    //     // std::cout << "hello lambda" <<std::endl;

      

    //     double  distancia1 = Distance(node1.dataPoint, pointTarget);
    //     double  distancia2 = Distance(node2.dataPoint, pointTarget);
                

    //      return (distancia1 ) > ( distancia2 ); 
    // }; 
    /* FIN DE LA FUNCION DE COMPARACION*/





    /* CREAMOS LA PRIORITY QUEUE */
    // std::priority_queue< mynode,
    //                      std::vector< mynode >,
    //                      decltype(compareFn)  >     classificationQueue(compareFn);


    // rellenadorDePoints(classificationQueue);

    // print_queue(classificationQueue);
    
    prueba<int> myPQnew ;
    // prueba myPQnew ;
    myPQnew.myPQ();


    std::cout << "pruebaaaaaaa";


    return 0;
}



