#include <iostream>
#include <sstream> // For stringstream
#include <string>

/*
    ESTA ES UNA VERSION ABREVIADA Y FUNCIONAL DE UNA binarySearchTree 
    BASANDONOS EN UNA linkedlist CON NODO DE UNION AL FRENTE Y ATRAS.
         nodeBefore   <- nodeRoot ->  nodeNext
*/


struct node
{
    int data;
    struct node *next;
    struct node *before;
    
};





class linked_list
{
    private:
        node *head;
        node *tail;

    public:
    
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }


    void agregarNodos(){
        
        std::cout << "\n Agregando Nodos \n" ;

       node *root = new node;
        
        if( head == NULL ) { // if LL is empty add newNode to Head
            std::cout << "\n Agregando Nodo ROOT \n" ;
            
            
            root->data =2;
            root->next=NULL;
            root->before=NULL;
            head = root;
        }

       
        //std::cout << showmeAll(root);

        std::cout << "\n Agregando Nodo 2 \n" ;
        node *nodo2 = new node;
        nodo2->data = 3;
        nodo2->next=NULL;
        nodo2->before=NULL;
        root->next= nodo2;

         std::cout << "\n Agregando Nodo 6 \n" ;
        node *nodo3 = new node;
        nodo3->data = 6;
        nodo3->next=NULL;
        nodo3->before=NULL;
        nodo2->next= nodo3;

         std::cout << "\n Agregando Nodo 4 \n" ;
        node *nodo4 = new node;
        nodo4->data = 4;
        nodo4->next=NULL;
        nodo4->before=NULL;
        nodo3->before= nodo4;

      std::cout << "\n Agregando Nodo 1 \n" ;
        node *nodo5 = new node;
        nodo5->data = -1;
        nodo5->next=NULL;
        nodo5->before=NULL;
        root->before= nodo5;

         std::cout << "\n TERMINANDO DE AGREGAR NODOS 2 \n" ;
    }// End agregarNodos







    void add_node(int newData) {

        // CREATING New_Node
        node *tmp = new node;
        tmp->data = newData;
        tmp->next   = NULL;
        tmp->before = NULL;

        // CREATING Node_Tracking
        node *n_tracking = new node;
        
        // Pointing Node_Tracking to Node_Root
        n_tracking=head;

        // CREATING NODO BACKUP
        node *n_back = new node;
        n_back=NULL;


        // looking for  next position for newData
        while (n_tracking != NULL ){
            
            std::cout << "iterando en :"<< n_tracking-> data << std::endl;

            if (newData >=n_tracking-> data){ // RIGHT

                std::cout << n_tracking-> data << "       -> VAMOS A LA DERECHA *" << std::endl;
                n_back     = n_tracking;
                n_tracking = n_tracking->next; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            

            }else  if (newData < n_tracking-> data) { // LEFT

                std::cout << " * VAMOS A IZQUIERDA  <-  " << n_tracking-> data  << std::endl;
                n_back     = n_tracking;
                n_tracking = n_tracking->before; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            
            }

        
        }//end while

        
       
        if( head == NULL ) { // if LL is empty add newNode to Head
            std::cout <<"anadiendo nodo :> "<<tmp->data << "  al Nodo ROOT "<< std::endl;

            head = tmp;
            //tail = tmp;

        }else {  // if get to the end of LL then add newNode to tail
            
           
            if( newData >= n_back->data){
                 std::cout <<"anadiendo el Nodo Nuevo -> "<< tmp->data << " a la DERECHA "<< std::endl;

                 n_back->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
           
            }else{
                 std::cout << tmp->data  <<" <-  anadiendo el Nodo Nuevo a la IZQUIERDA "<< std::endl;

                 n_back->before = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
           
            }
           
           
           
            //tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
        
        }


    }


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
        std::string miDato="";

        if (tmp->next ==NULL && tmp->before ==NULL)
        {
            std::cout << "\n>ambos son NULL\n";
            converter << tmp->data;
            converter  >>  miDato;

            return  miDato;
        }
        

        converter << tmp->data;
        converter  >>  miDato;

        if (tmp->next !=NULL && tmp->before !=NULL)
        {
            std::cout << "\n> Tiene datos en cada rama \n";
            return  showmeAll(tmp->before) + " | "+  miDato + " | "+showmeAll(tmp->next);
        }
        else if (tmp->next ==NULL && tmp->before !=NULL)
        {
            std::cout << "\n> Tiene datos en rama IZQUIERDA \n";
            return    showmeAll(tmp->before)+" | "+ miDato ;
        }
        else if (tmp->next !=NULL && tmp->before ==NULL)
        {
            std::cout << "\n> Tiene datos en rama DERECHA \n";
            return miDato +" | " + showmeAll(tmp->next)    ;
        }

        return "";


    } // End showmeAll
    



}; // End Class
















int main () {

     std::cout << "\n INICIANDO PROCESO \n" ;
    
    linked_list a;
   
    // a.agregarNodos();
    //  std::cout << "\nMOSTRANDO EL RESULTADO \n" << a.showmeAll();



    
    std::cout << "\n\nANDIENDO EL NUMERO 2 --------------------------------------------------------- \n";
    a.add_node(2);
    
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
    return 0;
}