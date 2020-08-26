#include <iostream>
#include <sstream> // For stringstream
#include <string>
#include<vector>

#include "point.h"

#include "KDTree.h"



/*
    ESTA ES UNA VERSION ABREVIADA Y FUNCIONAL DE UNA kdTree BASADA EN
    UNA linkedlist Y UNA  binarySearchTree

    -> UNA linkedlist CON NODO DE UNION AL FRENTE Y ATRAS.
         nodeBefore   <- nodeRoot ->  nodeNext
*/


struct node
{
    int data;
    Point<3> dataPoint;
    struct node *next;
    struct node *before;
    
};




// temsplate <typename ElementType>
class linked_list
{
    private:
        node *head;
        node *tail;
        // Point<3> pt; 

    public:
    
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }


    void agregarNodos(){
        /*
            ESTA ES UNA FUNCION SOLO DE PRUEBA QUE DEBE SER BORRADA A FUTURO
        */
        std::cout << "\n Agregando Nodos \n" ;

        node *root = new node;
        // head = root;

        if( head == NULL ) { // if LL is empty add newNode to Head
            std::cout << "\n Agregando Nodo ROOT \n" ;
            
            root->data = 1;
            root->dataPoint[0] = 1; //<-
            root->dataPoint[1] = 1;
            root->dataPoint[2] = 1;
            root->next=NULL;
            root->before=NULL;
            head = root;
        }

       
        //std::cout << showmeAll(root);

        std::cout << "\n Agregando Nodo 2 \n" ;
        node *nodo2 = new node;
        nodo2->data = 2;
        
        nodo2->dataPoint[0] = 2;
        nodo2->dataPoint[1] = 2;//<-
        nodo2->dataPoint[2] = 2;

        nodo2->next   = NULL;
        nodo2->before = NULL;
        root->next= nodo2;



        std::cout << "\n Agregando Nodo 3 \n" ;
        node *nodo3 = new node;
        nodo3->data = 3;
        
        Point<3> ptPrueba ;
        ptPrueba[0] =3;
        ptPrueba[1] =3;
        ptPrueba[2] =3;

        nodo3->dataPoint =ptPrueba;

        // nodo3->dataPoint[0] = 3;
        // nodo3->dataPoint[1] = 3;
        // nodo3->dataPoint[2] = 3;//<-
        nodo3->next   = NULL;
        nodo3->before = NULL;

        nodo2->before = nodo3;


        std::cout << "\n Agregando Nodo 4 \n" ;
        node *nodo4 = new node;
        nodo4->data = 4;

        nodo4->dataPoint[0] = 4;
        nodo4->dataPoint[1] = 4;
        nodo4->dataPoint[2] = 4;//<-

        nodo4->next=NULL;
        nodo4->before=NULL;
        nodo3->next= nodo4;

        std::cout << "\n TERMINANDO DE AGREGAR NODOS 2 \n" ;

    }// End agregarNodos







    void add_node(int newData, Point<3> pointNew) {
         std::cout << " INICIANDO add_node -------------------------------------------\n ";
        // CREATING New_Node
        node *tmp = new node;
        tmp->data = newData;
        tmp->dataPoint = pointNew;
        tmp->next   = NULL;
        tmp->before = NULL;

         
        // CREATING Node_Tracking
        node *n_tracking = new node;
        
        // Pointing Node_Tracking to Node_Root
        n_tracking=head;

        // CREATING NODO BACKUP
        node *n_back = new node;
        n_back=NULL;
       
        int indice = 0;
        int indicePoint= indice%3;
         int comparadorComponente ;
         int newPointComponente;
        if (n_tracking!= NULL){
              comparadorComponente = n_tracking->dataPoint[indicePoint];

            //std::cout << " DEBUGIN add_node 1 -------------------------------------------\n ";
    
             newPointComponente = pointNew[indicePoint];
        }else{
           // std::cout << " DEBUGIN add_node 2 -------------------------------------------\n ";
                comparadorComponente =0;
               newPointComponente =0;
        }
       
       
        // looking for  next position for newData
        while (n_tracking != NULL ){
            
            
            indicePoint= indice%3;
            std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "  indice de Posicion:> "<< indicePoint <<std::endl;
            
            comparadorComponente = n_tracking->dataPoint[indicePoint];
            newPointComponente = pointNew[indicePoint];
            //comparadorComponente =n_tracking-> data;

            if (newPointComponente >= comparadorComponente) { // RIGHT


                std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                n_back     = n_tracking;
                n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            

            }else  if (newPointComponente < comparadorComponente) { // LEFT

                std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                n_back     = n_tracking;
                n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
            }

            indice++;

        }//end while

       
        indice--;
        indicePoint = indice%3;
        newPointComponente = pointNew[indicePoint];

        if( head == NULL ) { // if LL is empty add newNode to Head
            std::cout <<"anadiendo nodo :> "<<tmp->data << "  al Nodo ROOT "<< std::endl;

            head = tmp;
            //tail = tmp;

        }else {  // if get to the end of LL then add newNode at the end of the branch
            
           
            if( newPointComponente >= n_back->dataPoint[indicePoint]){
                 
                std::cout << "anadiendo el Nodo Nuevo -> "<<  tmp->data  << " a la DERECHA "<< std::endl;
                n_back->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
           
            }else{

                std::cout << tmp->data  << " <-  anadiendo el Nodo Nuevo a la IZQUIERDA "<< std::endl;
                n_back->before = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
           
            }
           
           
           
            //tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
        
        }


    }// End add_node


    void  size(){
        /*TODO: Do the function for return the current size of the linkedlist */
    }

    node* getHead() const{
        return head;
    }


    bool exist(int dataToSearch){
        
        std::cout << "\n>Ingresando a exist(dataToSearch) \n";
        node *root = new node;
        root = getHead();

        return exist(dataToSearch,  root );
    }


    bool exist(int dataSearch, node* currentNode) {

        std::cout << "\n-> Iterando en exist( "<< currentNode->data <<" )-------- data a Buscar : "<< dataSearch <<"--------------------------------------------- \n";


        if(currentNode!=NULL  &&  currentNode->data == dataSearch)
        {
            std::cout  << " * ENCONTRADO... *" << std::endl;
            std::cout << "\n>En el nodo: "<< currentNode->data <<"\n";
            
             return true;
        }else if(currentNode==NULL)
        {
            std::cout  << " * NO ESTA ROOT *" << std::endl;      
            return false;
        }


        std::cout << "\n>Voy en el nodo: "<< currentNode->data <<"\n";

     
        if (currentNode->next ==NULL && currentNode->before ==NULL)
        {
            
            std::cout << "\n>ambos son NULL\n";
            return  false;

        }else if (currentNode->next !=NULL && currentNode->before !=NULL)
        {

            std::cout << "\n> <- Tiene datos en cada rama -> \n";
            bool resultado=  exist(dataSearch , currentNode->before )  || exist( dataSearch , currentNode->next);
            return resultado;
        
        }
        else if (currentNode->next ==NULL && currentNode->before !=NULL)
        {

            std::cout << "\n <- Tiene datos en rama IZQUIERDA \n";
            bool resultado=  exist(dataSearch, currentNode->before )  ;
            return resultado;
          
        }
        else if (currentNode->next !=NULL && currentNode->before ==NULL)
        {

            std::cout << "\n> Tiene datos en rama DERECHA -> \n";
            bool resultado=  exist( dataSearch , currentNode->next )  ;
            return resultado;
           
        }


        return false;
    }


    /*
  bool remove(int dataToSearch){
        
        std::cout << "\n>Ingresando a exist(dataToSearch) \n";
        node *root = new node;
        root = getHead();

        return remove(dataToSearch,  root );
    }


    bool remove(int dataSearch, node* currentNode) {

        std::cout << "\n-> Iterando en remove( "<< currentNode->data <<" )-------- data a Remover : "<< dataSearch <<"--------------------------------------------- \n";


        if(currentNode!=NULL  &&  currentNode->data == dataSearch)
        {
            std::cout  << " * ENCONTRADO... *" << std::endl;
            std::cout << "\n>En el nodo: "<< currentNode->data <<"\n";
            
             return true;
        }else if(currentNode==NULL)
        {
            std::cout  << " * NO ESTA ROOT *" << std::endl;      
            return false;
        }


        std::cout << "\n>Voy en el nodo: "<< currentNode->data <<"\n";

     
        if (currentNode->next ==NULL && currentNode->before ==NULL)
        {
            
            std::cout << "\n>ambos son NULL\n";
            return  false;

        }else if (currentNode->next !=NULL && currentNode->before !=NULL)
        {

            std::cout << "\n> <- Tiene datos en cada rama -> \n";
            bool resultado=  remove(dataSearch , currentNode->before )  || remove( dataSearch , currentNode->next);
            return resultado;
        
        }
        else if (currentNode->next ==NULL && currentNode->before !=NULL)
        {

            std::cout << "\n <- Tiene datos en rama IZQUIERDA \n";
            bool resultado=  remove(dataSearch, currentNode->before )  ;
            return resultado;
          
        }
        else if (currentNode->next !=NULL && currentNode->before ==NULL)
        {

            std::cout << "\n> Tiene datos en rama DERECHA -> \n";
            bool resultado=  remove( dataSearch , currentNode->next )  ;
            return resultado;
           
        }


        return false;
    }
    */

    // bool contains(Point<3>& pt) {
       
    //     // node *root = head;
    //     node *root = new node;
    //     root= getHead();
        
    //     std::cout  << "* ESTAMOS EN contains() *" << std::endl;
    //     return contains(root, pt);

    // }


    bool contains( Point<3>& pt ) //node *root,
    {
        std::cout << "\n>Ingresando a containsRecursive (Node , Point) ---------------------------------------------------------\n";

       
    
        // CREATING New_Node
        // node *tmp = new node;
        // tmp->data = newData;
        // tmp->dataPoint = pointNew;
        // tmp->next   = NULL;
        // tmp->before = NULL;

         
        // CREATING Node_Tracking
        node *n_tracking = new node;
        
        // Pointing Node_Tracking to Node_Root
        n_tracking=head;

        // CREATING NODO BACKUP
        node *n_back = new node;
        n_back=NULL;
       
        int indice = 0;
        int indicePoint= indice%3;
        int comparadorComponenteNodo ;
        int comparadorComponentePoint;



        if (n_tracking!= NULL){
              comparadorComponenteNodo = n_tracking->dataPoint[indicePoint];

            //std::cout << " DEBUGIN add_node 1 -------------------------------------------\n ";
    
             comparadorComponentePoint = pt[indicePoint];
        }else{
           // std::cout << " DEBUGIN add_node 2 -------------------------------------------\n ";
                comparadorComponenteNodo =0;
               comparadorComponentePoint =0;
        }
       
       
        // looking for  next position for newData
        while (n_tracking != NULL ){
            
            
            indicePoint= indice%3;
            std::cout << "iterando en :> "<<  n_tracking->dataPoint[indicePoint] << "Indice General "<< indice <<"  indice de Posicion Point:> "<< indicePoint <<std::endl;
            

            comparadorComponenteNodo  =  n_tracking->dataPoint[indicePoint];
            comparadorComponentePoint =  pt[indicePoint];
       

            if (comparadorComponentePoint > comparadorComponenteNodo) { // RIGHT

                // if(pt[0] == n_tracking->dataPoint[0]   &&   pt[1] == n_tracking->dataPoint[1]  && pt[2] == n_tracking->dataPoint[2] ) {
                //     return true;
                // }else{
                    std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                    n_back     = n_tracking;
                    n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                // }

            
            

            }else  if (comparadorComponentePoint < comparadorComponenteNodo) { // LEFT

                std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                n_back     = n_tracking;
                n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
            }else if (comparadorComponentePoint == comparadorComponenteNodo) { // RIGHT

                 if(pt[0] == n_tracking->dataPoint[0]   &&   pt[1] == n_tracking->dataPoint[1]  && pt[2] == n_tracking->dataPoint[2] ) {
                    return true;
                 }
            
            }


            indice++;

        }//end while


        return false;

    } // End contains
    

    

    std::string showmeAll() {
        // node *root = head;
        node *root = new node;
        root= getHead();
        
        std::cout  << " ESTAMOS EN showmeAll() *" << std::endl;
        return showmeAll(root);
    }


    std::string showmeAll(node *root) 
    {
       

        std::cout << "\n>Ingresando a showmeALL(Node) \n";
    
        if(root==NULL){
            return "";
        }
        std::cout << "\n>voy en el nodo: "<< root->data <<"\n";
        
        node *tmp = root;

        std::stringstream converter;

        std::stringstream converterA;
        std::stringstream converterB;
        std::stringstream converterC;

        std::string miDatoA="";
        std::string miDatoB="";
        std::string miDatoC="";

        std::string miDato="";

        if (tmp->next ==NULL && tmp->before ==NULL)
        {
            std::cout << "\n>ambos son NULL\n";
            
            converterA << tmp->dataPoint[0];
            converterA  >>  miDatoA;
            
            converterB << tmp->dataPoint[1];
            converterB  >>  miDatoB;
            
            converterC << tmp->dataPoint[2];
            converterC  >>  miDatoC;
            
            miDato = miDatoA + miDatoB + miDatoC;

            // converter << tmp->data;
            // converter  >>  miDato;
            // converter.clear();
           
            return  miDato;
        }
        
        converterA << tmp->dataPoint[0];
        converterA  >>  miDatoA;
        converterB << tmp->dataPoint[1];
        converterB  >>  miDatoB;
        converterC << tmp->dataPoint[2];
        converterC  >>  miDatoC;

        miDato = miDatoA + miDatoB + miDatoC;
        // converter << tmp->data;
        // converter  >>  miDato;

        if (tmp->next != NULL   &&   tmp->before != NULL)
        {
            std::cout << "\n> Tiene datos en cada rama \n";
            return  showmeAll(tmp->before) + " | "  +  miDato +  " | "+showmeAll(tmp->next);
        }
        else if (tmp->next == NULL && tmp->before != NULL)
        {
            std::cout << "\n> Tiene datos en rama IZQUIERDA \n";
            return    showmeAll(tmp->before)+" | "+ miDato ;
        }
        else if (tmp->next != NULL && tmp->before == NULL)
        {
            std::cout << "\n> Tiene datos en rama DERECHA \n";
            return miDato +" | " + showmeAll(tmp->next)    ;
        }

        return "";


    } // End showmeAll
    

}; // End Class


















int main () {

     std::cout << "\n INICIANDO PROCESO \n" ;
    
    //typedef linked_list <Point<3> > a;
      linked_list  a;
   
    // a.agregarNodos();
    //  std::cout << "\nMOSTRANDO EL RESULTADO \n" << a.showmeAll();



    
    // std::cout << "\n\nANDIENDO EL NUMERO 3 1 4 --------------------------------------------------------- \n";
    // Point<3> pointTemp;
    // pointTemp[0]=3;
    // pointTemp[1]=1;
    // pointTemp[2]=4;
    // a.add_node(1, pointTemp);


    // std::cout << "\n\nANDIENDO EL NUMERO 2 2 2 --------------------------------------------------------- \n";
   
    // pointTemp[0]=2;
    // pointTemp[1]=3;
    // pointTemp[2]=7;
    // a.add_node(2, pointTemp);


    // std::cout << "\n\nANDIENDO EL NUMERO 4 3 4 --------------------------------------------------------- \n";
    
    // pointTemp[0]=4;
    // pointTemp[1]=3;
    // pointTemp[2]=4;
    // a.add_node(3, pointTemp);


    // std::cout << "\n\nANDIENDO EL NUMERO 6 1 4 --------------------------------------------------------- \n";
   
    // pointTemp[0]=6;
    // pointTemp[1]=1;
    // pointTemp[2]=4;
    // a.add_node(4, pointTemp);



    // std::cout << "\n\nANDIENDO EL NUMERO 5 2 5 --------------------------------------------------------- \n";

    // pointTemp[0]=5;
    // pointTemp[1]=2;
    // pointTemp[2]=5;
    // a.add_node(5, pointTemp);



    // std::cout << "\n\nANDIENDO EL NUMERO 4 0 6 --------------------------------------------------------- \n";
    
    // pointTemp[0]=4;
    // pointTemp[1]=0;
    // pointTemp[2]=6;
    // a.add_node(6, pointTemp);

    // std::cout << "\n\nANDIENDO EL NUMERO 7 1 6 --------------------------------------------------------- \n";

    // pointTemp[0]=7;
    // pointTemp[1]=1;
    // pointTemp[2]=6;
    // a.add_node(7, pointTemp);

    // std::cout << "\n\nANDIENDO EL NUMERO 2 4 5 --------------------------------------------------------- \n";
   
    // pointTemp[0]=2;
    // pointTemp[1]=4;
    // pointTemp[2]=5;
    // a.add_node(8, pointTemp);

    // std::cout << "\n\nANDIENDO EL NUMERO 2 1 3 --------------------------------------------------------- \n";
 
    // pointTemp[0]=2;
    // pointTemp[1]=1;
    // pointTemp[2]=3;
    // a.add_node(9, pointTemp);

    // std::cout << "\n\nANDIENDO EL NUMERO 0 5 7 --------------------------------------------------------- \n";

    // pointTemp[0]=0;
    // pointTemp[1]=5;
    // pointTemp[2]=7;
    // a.add_node(10, pointTemp);



    // std::cout << "\n\nANDIENDO EL NUMERO 1 4 4 --------------------------------------------------------- \n";
   
    // pointTemp[0]=1;
    // pointTemp[1]=4;
    // pointTemp[2]=4;
    // a.add_node(11, pointTemp);

    // std::cout << "\n\n---------- ** MOSTRANDO EL RESULTADO **  ---------------------------------------------------------\n" << a.showmeAll() <<"\n";
    // std::cout<<"\n\n\n\n\n\n";
    
    // std::cout << "\n\n CHEQUEANDO SI EL POINT [0,5,7] ESTA EN EL ARBOL \n";
    // Point<3> pointTest;
    // pointTest[0] = 15;
    // pointTest[1] = 2;
    // pointTest[2] = 15;
    // std::string resultado = (a.contains(pointTest)== true)? "si":"no";
    // std::cout << "\n\nEl punto , esta? = " << resultado ;//[2,1,3]


    /*
    std::cout << "\n\nANDIENDO EL NUMERO 3 --------------------------------------------------------- \n";
    a.add_node(3);
    
    std::cout << "\n\nANDIENDO EL NUMERO 6 \n";
    a.add_node(6);

     std::cout << "\n\nANDIENDO EL NUMERO 4 \n";
    a.add_node(4);

     std::cout << "\nANDIENDO EL NUMERO -1 \n";
     a.add_node(-1);

    std::cout << "\nANDIENDO EL NUMERO 1 \n";
     a.add_node(1);

    std::cout << "\nANDIENDO EL NUMERO 0 \n";
     a.add_node(0);

     std::cout << "\n\n---------- ** MOSTRANDO EL RESULTADO **  ---------------------------------------------------------\n" << a.showmeAll() <<"\n";

    std::cout << "\n\n CHEQUEANDO SI EL NUMERO 4 ESTA EN EL ARBOL \n";
    
    std::string resultado = (a.exist(6)== 1)? "si":"no";
    std::cout << "Resultado(6) = " << resultado ;
    */



   // PROBANDO EL OBJETO KDTree
    std::cout << "\nPROBANDO EL OBJETO KDTree\n";

    KDTree<2, std::string> myKDTree ;
   
   // std::cout << "\n\n\n\nesta vacio? el KDTree = " << myKDTree.empty(); 


    std::cout << "\n\nANDIENDO EL NUMERO 2, 3 -> pera --------------------------------------------------------- \n";
    Point<2>pointTemp;
    pointTemp[0]=2;
    pointTemp[1]=3;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 2, 4 pera --------------------------------------------------------- \n";
    pointTemp[0]=2;
    pointTemp[1]=4;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 3, 4 pera --------------------------------------------------------- \n";
    pointTemp[0]=3;
    pointTemp[1]=4;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 2, 5 pera --------------------------------------------------------- \n";
    pointTemp[0]=2;
    pointTemp[1]=5;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 3, 5 Pera --------------------------------------------------------- \n";
    pointTemp[0]=3;
    pointTemp[1]=5;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 2.5,  6 pera --------------------------------------------------------- \n";
    pointTemp[0]=2.5 ;
    pointTemp[1]=6;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 4, 6 Pera --------------------------------------------------------- \n";
    pointTemp[0]=4;
    pointTemp[1]=6;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 3, 6.5 Pera --------------------------------------------------------- \n";
    pointTemp[0]=3;
    pointTemp[1]=6.5;
    myKDTree.insert(pointTemp, "pera");


    std::cout << "\n\nANDIENDO EL NUMERO 9, 1 manzana --------------------------------------------------------- \n";
    pointTemp[0]=9;
    pointTemp[1]=1;
    myKDTree.insert(pointTemp, "manzana");




    std::cout << "\n\nANDIENDO EL NUMERO 11, 1 manzana --------------------------------------------------------- \n";
    pointTemp[0]=11;
    pointTemp[1]=1;
    myKDTree.insert(pointTemp, "manzana");



    std::cout << "\n\nANDIENDO EL NUMERO 10.5, 2.5 manzana --------------------------------------------------------- \n";
    pointTemp[0]=10.5;
    pointTemp[1]=2.5;
    myKDTree.insert(pointTemp, "manzana");
    


    std::cout << "\n\nANDIENDO EL NUMERO 10, 1 manzana --------------------------------------------------------- \n";
    pointTemp[0]=10;
    pointTemp[1]=1;
    myKDTree.insert(pointTemp, "manzana");


    std::cout << "\n\nANDIENDO EL NUMERO 12, 3 manzana --------------------------------------------------------- \n";
    pointTemp[0]=12;
    pointTemp[1]=3;
    myKDTree.insert(pointTemp, "manzana");


    std::cout << "\n\nANDIENDO EL NUMERO 9.5, 2.5 manzana --------------------------------------------------------- \n";
    pointTemp[0]=9.5;
    pointTemp[1]=2.5;
    myKDTree.insert(pointTemp, "manzana");


    std::cout << myKDTree.showmeAll() <<std::endl;
    std::cout <<"caaantidad de nodos = " << myKDTree.size() << std::endl;



     Point<2> pointTest ;
     pointTest[0] =1;
     pointTest[1] =3;
     std::cout <<"probaaanado el k-nn = " << myKDTree.kNNValue(pointTest,2);
    
    
    // std::cout <<"probaaando si contiene el nodo (10, 1) = " << myKDTree.contains(pointTemp);

    // PRUEBA CALCULO DISTANCIA

    // Point<2> pointOne ;
    // pointOne[0]= 5;
    // pointOne[1]= 6;
  
    
    // Point<2> pointTwo ;
    // pointTwo[0]= 8 ;
    // pointTwo[1]= 3 ;

    // double myDistance = Distance(pointOne, pointTwo);

    // std::cout << "distancia entre dos puntos" << myDistance;


    // std::cout << "\n\n CHEQUEANDO SI EL POINT [0,5,7] ESTA EN EL ARBOL \n";
    // Point<3> pointTest;
    // pointTest[0] = 3;
    // pointTest[1] = 2;
    // pointTest[2] = 4;

    // std::string resultado = (myKDTree.contains(pointTest)== true)? "si":"no";
    // std::cout << "\n\nEL PUNTO [3,2,4] , ESTA ? = " << resultado  <<"\n\n";//[2,1,3]


    // std::cout << "\n Anadiendo el punto [7, 8, 9] mediante el uso del operado[point]\n";
    // pointTemp[0]=7;
    // pointTemp[1]=8;
    // pointTemp[2]=9;
    // myKDTree[pointTemp];
    
    
    // std::cout << "\n\n---------- ** MOSTRANDO EL RESULTADO **  ---------------------------------------------------------\n";
    // std::cout << myKDTree.showmeAll() <<"\n";


    // std::cout << "\n Anadiendo el punto  [7, 8, 9] de nuevo mediante el uso del operado[point]\n";
    // pointTemp[0]=7;
    // pointTemp[1]=8;
    // pointTemp[2]=9;
    // std::cout<< myKDTree[pointTemp] << "---------------\n";
     
    
    // std::cout << "\n\n---------- ** MOSTRANDO EL RESULTADO **  ---------------------------------------------------------\n";
    // std::cout << myKDTree.showmeAll() <<"\n";

    // std::cout << ">Tamano del KDTree = " << myKDTree.size() <<"\n\n"; 
    // std::cout << ">Esta vacio? el KDTree = " << myKDTree.empty()<<"\n\n";  
    
    // pointTemp[0]=3;
    // pointTemp[1]=1;
    // pointTemp[2]=4;
    // std::cout << "usan la funcion at(point) KDTree = " << myKDTree.at(pointTemp); 









    // PROBANDO EL OBJETO Point
    /*
    Point <3> p;
    p[0] = 1.87;
    p[1] = 2.10;
    p[2] = 3.54;

    Point<3>::iterator itrEnd= p.end();
    int tamano = p.size();
    std::cout << "tamano del point " << tamano <<std::endl;
    for (Point<3>::iterator itr = p.begin() ;  itr < itrEnd ; itr++ ) {
        
        std::cout << *itr <<std::endl;

    }
    */


    return 0;
}



