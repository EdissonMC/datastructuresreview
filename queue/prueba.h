
#ifndef PRUEBAS_INCLUDED
#define PRUEBAS_INCLUDED


#include <iostream>
#include <vector>
#include <queue>
#include "point.h"
#include <string> 

#include <functional>
#include <set>
#include <unordered_set>


  

template<typename myType> 
class prueba
{   
    private:

    struct node
                {
                    int data;
                    //Point<N> dataPoint;
                    Point<2> dataPoint;
                    struct node *next;
                    struct node *before;
                    // ElemType classification;     
                    std::string classification;     
                };  

    public :   
          
        void myPQ();

        template<typename CompT>
        void rellenadorDePoints(std::priority_queue< node,
                         std::vector< node >,CompT  >& classificationQueue); 

        template<typename T> 
        void print_myqueue(T& q);

};



template<typename myType> 
template<typename CompT>
void prueba<myType>::rellenadorDePoints(std::priority_queue< node,
                         std::vector< node >,CompT  >& classificationQueue) {

// template<typename CompT>
// void prueba::rellenadorDePoints(std::priority_queue< node,
//                          std::vector< node >,CompT  >& classificationQueue) {

    node node1 ;
    node1.dataPoint [0] = 2;
    node1.dataPoint [1] = 3;
    node1.classification = "pera";

    classificationQueue.push(node1);
    

    
    node node2 ;
    node2.dataPoint [0] = 2;
    node2.dataPoint [1] = 4;
    node2.classification = "pera";

    classificationQueue.push(node2);


    node node3 ;
    node3.dataPoint [0] = 3;
    node3.dataPoint [1] = 4;
    node3.classification = "pera";
    classificationQueue.push(node3);

    node node4 ;
    node4.dataPoint [0] = 2;
    node4.dataPoint [1] = 5;
    node4.classification = "pera";
   classificationQueue.push(node4);


    node node5 ;
    node5.dataPoint [0] = 3;
    node5.dataPoint [1] = 5;
    node5.classification = "pera";
   classificationQueue.push(node5);

    node node6 ;
    node6.dataPoint [0] = 11;
    node6.dataPoint [1] = 1;
    node6.classification = "manzana";
   classificationQueue.push(node6);

    node node7 ;
    node7.dataPoint [0] = 10.5;
    node7.dataPoint [1] = 2.5;
    node7.classification = "manzana";
       classificationQueue.push(node7);


    node node8 ;
    node8.dataPoint [0] = 10;
    node8.dataPoint [1] = 1;
    node8.classification = "manzana";
       classificationQueue.push(node8);

    node node9 ;
    node9.dataPoint [0] = 12;
    node9.dataPoint [1] = 3;
    node9.classification = "manzana";
       classificationQueue.push(node9);


    node node10 ;
    node10.dataPoint [0] = 9.5;
    node10.dataPoint [1] = 2.5;
    node10.classification = "manzana";

    classificationQueue.push(node10);
}


template<typename myType> 
template<typename T> 
void prueba<myType>::print_myqueue(T& q) {

// template<typename T> 
// void prueba::print_myqueue(T& q) {
// void print_queue(T& q) {

    while(!q.empty()) {
        
        node myNode= q.top();
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


template<typename myType> 
void prueba<myType>::myPQ(){

// void prueba::myPQ(){


    /* PRIORITY QUEUE PARA STRINGS */

    Point<2> pointTarget;
    pointTarget [0]= 1;
    pointTarget [1] =3;

    /* FUNCION DE COMPARACION */
    auto compareFn = [&pointTarget] ( node node1 ,  node node2 ) {
     
    
        double  distancia1 = Distance(node1.dataPoint, pointTarget);
        double  distancia2 = Distance(node2.dataPoint, pointTarget);
                

         return (distancia1 ) > ( distancia2 ); 
    }; 
    
    
    /* FIN DE LA FUNCION DE COMPARACION*/
    /* CREAMOS LA PRIORITY QUEUE */
    
    std::priority_queue< node,
                         std::vector< node >,
                         decltype(compareFn)  >     classificationQueue(compareFn);


     rellenadorDePoints(classificationQueue);
     print_myqueue(classificationQueue);

}


#endif