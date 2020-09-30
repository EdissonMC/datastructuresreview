#include <iostream>

struct node
{
   int data;
   struct node * next_node;
   struct node * before_node;
};

struct nodeCheker
{
   
   struct node * currentNode;
   struct node * nodePointer;
};

void showBst(node& nodeHead ) {

    
    std::cout << "MOSTRANDO LINKD LIST  "<< &nodeHead <<std::endl;
    node *nodeTracking = &nodeHead;

    std::cout << "MOSTRANDO LINKD LIST2 "<< nodeTracking <<std::endl;

    //std::cout << ">Node data " << (*nodeTracking).data <<std::endl; 
    // std::cout << (*nodeTracking).next_node <<std::endl; 
        
    while (true ) {
        
        
        std::cout << "> Node data "<< (*nodeTracking).data << "> address "<<  (*nodeTracking).next_node  <<std::endl; 
        
        if ( (*nodeTracking).next_node == NULL) {
            break;
        }

        nodeTracking = (*nodeTracking).next_node;
    }

}




int insert2(node& nodeHead, int newData, node& newNode){
    
    std::cout << "ANADIENDO el node " << &nodeHead <<std::endl ;

    // node newNode;
    // newNode.data = newData;
    // newNode.next_node = NULL;
    // newNode.before_node = NULL;
    // nodeHead.next_node = &newNode;

  
    newNode.data = newData;
    newNode.next_node = NULL;
    newNode.next_node = NULL;
    nodeCheker nodeTracking ;
    nodeTracking.currentNode = &nodeHead;

    (*nodeTracking.currentNode).next_node=&newNode;

    // node body2;
    // body2.data = 14;
    // body2.next_node = NULL;
    // body1.next_node = &body2;

    std::cout << "> newNode addres = " << &newNode <<std::endl; 
    std::cout << "> adding node1 = " << (nodeHead.next_node) <<std::endl; 

    // showBst( nodeHead );
    return 0;
    
    // std::cout << "MOSTRANDO LINKD LIST "<< &nodeHead <<std::endl;
    // node *nodeTracking = &nodeHead;

    // std::cout << "MOSTRANDO LINKD LIST2 "<< nodeTracking <<std::endl;

    // std::cout << ">Node data " << (*nodeTracking).data <<std::endl; 
    // // std::cout << (*nodeTracking).next_node <<std::endl; 
        
    // while ( (*nodeTracking).next_node != NULL ) {
        
    //      nodeTracking = (*nodeTracking).next_node;
    //     std::cout << ">Node data "<< (*nodeTracking).data <<std::endl; 
       
    // }

}




int insert(node& nodeHead, int newData, node& newNode) {
     std::cout << "VAMOS A INSERTAR... " << newData <<std::endl;

    nodeCheker nodeTracking;
    nodeTracking.currentNode = &nodeHead;

    if( newData < nodeHead.data ) {
         std::cout <<  "Apuntando hacia abajo :";
        nodeTracking.nodePointer = nodeHead.before_node;

        if( nodeTracking.nodePointer != NULL){
            std::cout <<  "el puntero inicial"<< nodeTracking.nodePointer->data<<std::endl;
        } else{
             std::cout <<  " puntero es NULL\n";
        }  
       

    } else {
         std::cout <<  "Apuntando hacia arriba :  ";
          nodeTracking.nodePointer= nodeHead.next_node;
           if( nodeTracking.nodePointer != NULL){
                std::cout << "el puntero inicial" << nodeTracking.nodePointer->data<<std::endl;
           }else{
                std::cout <<  " puntero es NULL\n";
           }
          
    }
   
    

    while ( nodeTracking.nodePointer != NULL ) {
          
         std::cout << "..... While .....\n";

         if( (*nodeTracking.currentNode).data == newData)
         {
            std::cout << "ya esta en el arbol" <<std::endl; 
            return 0;

        }else if(  newData > (*nodeTracking.currentNode).data )
        {      

            std::cout<<"vefirivando es mayor :"<<   (*nodeTracking.currentNode).data <<std::endl;
            
            if((*nodeTracking.currentNode).next_node==NULL){
                break;
            }

            std::cout << "Vamos a next_Node " <<std::endl; 
            nodeTracking.currentNode = nodeTracking.nodePointer;
            nodeTracking.nodePointer = (*nodeTracking.currentNode).next_node;

           
            
        }else if( newData <  (*nodeTracking.currentNode).data   )
        {

            std::cout<<"verificando es menor que : " <<   (*nodeTracking.currentNode).data   <<std::endl;
            
            if(( *nodeTracking.currentNode).before_node==NULL){
                break;
            }
            std::cout << "Vamos a before_Node "  <<std::endl; 
               nodeTracking.currentNode = nodeTracking.nodePointer;
            nodeTracking.nodePointer = (*nodeTracking.currentNode).before_node;


        
        }

    }




    std::cout << "SALIMOS DEL while.. VAMOS A ANADIR .." <<std::endl;
    
   
    newNode.data = newData;
    newNode.next_node = NULL;
    newNode.before_node = NULL;

  std::cout << "*nodeTracking.currentNode).data .. " << (*nodeTracking.currentNode).data<<"  newData "<<newData <<std::endl;
     if( (*nodeTracking.currentNode).data   == newData)
    {
            std::cout << "ya existe" <<std::endl; 
            return 0;

    }
    else if(  newData >   (*nodeTracking.currentNode).data )
    {
           
             (*nodeTracking.currentNode).next_node = &newNode;  

            nodeTracking.currentNode  =  (*nodeTracking.currentNode).next_node;
            std::cout << "Node anadido a data_next ... "<<  (*nodeTracking.currentNode).data <<std::endl; 

    }
    else if( newData <   (*nodeTracking.currentNode).data )
    {
            (*nodeTracking.currentNode).before_node = &newNode;   
           nodeTracking.currentNode  =  (*nodeTracking.currentNode).before_node;
            std::cout << "Node anadido a data_before ..."<<   (*nodeTracking.currentNode).data  <<std::endl;  

        }


         std::cout << "TERMINANDO ----------------------------------------------- \n\n\n";

    return 0;
    
}





int main () {

    node head;

    head.data = 1;
    head.next_node =NULL;
    head.before_node =NULL;
    std::cout << &head << std::endl;



    //  node myNewNode;
//    insert2(head,14, myNewNode);
    //  insert(head,14, myNewNode);
    // std::cout <<"TERMINANDO DE INSERTAR\n";

    // node myNewNode2;
    //   insert(head,16, myNewNode2);
    //     std::cout <<"TERMINANDO DE INSERTAR\n";
    // showBst( head );


    


    for (int i = 2 ; i<6;  i++){

        node* myNewNode3 = new node;
        std::cout << "-------------------------creacionNuevoNodo address : " << &myNewNode3;
        insert(head,i, *myNewNode3);
        std::cout <<"TERMINANDO DE INSERTAR\n";
    }


      showBst( head );

    // insert2(head, 14);
    // insert(head, 3);

   
    // body1.data = 12;
    // body1.next_node = NULL;
    // head.next_node = &body1;


    // node body2;
    // body2.data = 3;
    // body2.next_node = NULL;
    // body1.next_node = &body2;

    // showBst(head);




}