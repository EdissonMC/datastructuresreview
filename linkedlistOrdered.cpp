#include <iostream>

/*
    ESTA ES UNA VERSION ABREVIADA Y FUNCIONAL DE UNA linkedlist  ASCENDENTE ORDENADA
    QUE PERMITE ANADIR NUEVOS NODOS Y ESTOS SERAN LOCALIZADOS SEGUN EL VALOR QUE ALOJAN.

    THIS IS A SHORT AND FUNCTIONAL VERSION OF AN ORDERED ASCENDING linkedlist
    THAT ALLOWS TO ADD NEW NODES AND THESE WILL BE LOCATED ACCORDING TO THE VALUE THAT THEY HOLD.

    Node1(1) ->  Node2(2) -> Node3(3) 
*/


struct node
{
    int data;
    struct node *next;
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

    void add_node(int newData) {

        node *tmp = new node;
        tmp->data = newData;
        tmp->next = NULL;

        node *n_tracking = new node;
        n_tracking=head;


        // looking for  next position for newData
        while (n_tracking != NULL ){
            
            std::cout << "iterando :"<< n_tracking-> data << std::endl;

            // if (tmp->data > newData){
            //      std::cout << tmp-> data << " * SI ESTA *" << std::endl;
              
            // }

            if (n_tracking->next != NULL &&   n_tracking->next->data  >= newData){
                
                
                // std::cout << "NodoNuevo : " <<  tmp << " data :" << tmp->data << std::endl;
                
                // std::cout << "\nNodo_tracking : " <<  n_tracking << " data :" << n_tracking->data << std::endl;
                // std::cout << "Nodo_tracking apunta a : " <<  n_tracking->next << " data :" << n_tracking->next->data << std::endl;
                
                // std::cout << "\n <- Anadiendo el nuevo nodo -> " <<std::endl;
                

                tmp->next = n_tracking->next;      // REAPUNTANDO tail AL NUEVO NODO
                // std::cout << "\nNodoNuevo actual : " <<  tmp << " data :" << tmp->data << std::endl;  
                // std::cout << "NodoNuevo ahora apunta a adrress : " << tmp->next <<   " data: "<< tmp->next->data  <<std::endl;
                

                n_tracking->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
                // std::cout << "\nNodo_tracking : " <<  n_tracking << " data :" << n_tracking->data << std::endl;
                // std::cout << "Nodo_tracking ahora apunta a adrress :"<< n_tracking->next << " data: " << n_tracking->next->data  <<std::endl;
                
                // std::cout << "\nNodoNuevo actual : " <<  tmp << " data :" << tmp->data << std::endl;  
                //  std::cout << "NodoNuevo ahora apunta a adrress : " << tmp->next <<   " data: "<< tmp->next->data  <<std::endl;
               
            //    if ( tmp->next->next == NULL) {
            //         std::cout << "Nodo despues de 5 es NULL : " <<std::endl;
            //    }
               
                
                

               return ;
            }else{
                n_tracking = n_tracking->next;          
            }

        
        }
        
        std::cout <<"anadiendo el nodo inicial solamente"<< std::endl;

        if( head ==NULL ) {
            head = tmp;
            tail = tmp;
        }else {
            tail->next = tmp; // APUNTANDO EL NEXT DEL ULTIMO NODO AL NUEVO NODO
            tail = tail->next;      // REAPUNTANDO tail AL NUEVO NODO
        }


    }




    node* getHead() const{
        return head;
    }




    bool exist(int dataSearch) {

        node *tmp = new node;
        tmp= getHead();

        while (tmp != NULL){
             //std::cout << tmp-> data << std::endl;

            if (tmp->data== dataSearch){
                 std::cout << tmp-> data << " * SI ESTA *" << std::endl;
                return true;
            }
           

            tmp = tmp->next;
        }

         std::cout  << " * NO ESTA *" << std::endl;
        return false;
    }




    bool remove(int dataSearch) {

        node *tmp = new node;
        tmp = getHead();


        node *tmpPrev = new node;
        tmpPrev = NULL;

        while (tmp != NULL){
             //std::cout << tmp-> data << std::endl;

            if (tmp->data== dataSearch){
                
                std::cout << tmp-> data << " * SI ESTA  -> BORRANDO *" << std::endl;

                if( tmpPrev == NULL && tmp->next !=NULL ) {
                    std::cout << "chequeo A"<<std::endl;

                    //head = tmp->next;
                    tmp->data  = tmp->next->data;
                    tmp->next  = tmp->next->next;

                }else if( tmpPrev == NULL && tmp->next == NULL ) {
                     std::cout << "chequeo B"<<std::endl;
                   // tmp = getHead();
                    head = NULL;
                    tail  = NULL;
                }else{
                     std::cout << "chequeo C"<<std::endl;
                    tmpPrev->next  =  tmp->next;
                    tmp =  tmp->next;
                }

            
                return true;
            }
           
             tmpPrev = tmp;
             tmp = tmp->next;
          
        }

         std::cout  << " * NO ESTA s *" << std::endl;
        return false;
    }


    void showmeLL()
    {

        node *tmp = new node;
        tmp= getHead();
        int contador =0;

        while (tmp != NULL){
            
            std::cout  << tmp << " data = "<< tmp-> data << "    address next "<<tmp->next << std::endl;

            tmp = tmp->next;
            //  if(contador ==4){
            
            //     exit(0);

            //  }
            contador++;
        }

    }

}; // End Class
















int main () {

    
     linked_list a;

    std::cout<<"\n\n\n ANADIENDO  EL 1" << std::endl;
    a.add_node(1);
      std::cout<<"\n\n\n MOSTRANDO TODA LA LINKEDLIST  -----------  " << std::endl;
     a.showmeLL();


    std::cout<<"\n\n\n ANADIENDO  EL 3" << std::endl;
    a.add_node(3);
  std::cout<<"\n\n\n MOSTRANDO TODA LA LINKEDLIST  -----------  " << std::endl;
     a.showmeLL();


    std::cout<<"\n\n\n ANADIENDO  EL 5" << std::endl;
    a.add_node(5);
    std::cout<<"\n\n\n MOSTRANDO TODA LA LINKEDLIST  -----------  " << std::endl;
     a.showmeLL();


    std::cout<<"\n\n\n ANADIENDO  EL 4" << std::endl;
    a.add_node(4);

  std::cout<<"\n\n\n ANADIENDO  EL 43" << std::endl;
    a.add_node(43);

  std::cout<<"\n\n\n ANADIENDO  EL 22" << std::endl;
    a.add_node(22);

      std::cout<<"\n\n\n ANADIENDO  EL 7" << std::endl;
    a.add_node(7);



     std::cout<<"\n\n\n MOSTRANDO TODA LA LINKEDLIST  -----------  " << std::endl;
     a.showmeLL();

     a.remove(1);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
    a.showmeLL();


  a.remove(5);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 5" << std::endl;
    a.showmeLL();

 a.remove(7);
     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 7" << std::endl;
    a.showmeLL();

//     a.add_node(2);
//     a.add_node(3);
//     a.add_node(43);
//      a.add_node(24);

//      a.remove(1);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//     a.add_node(84);
//     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 84 DE LL" << std::endl;
//     a.showmeLL();


//   a.remove(2);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//   a.remove(43);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//   a.remove(84);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//   a.remove(3);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//        a.remove(24);
//      std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS DESPUES DE BORRAR EL 1" << std::endl;
//      a.showmeLL();

//     a.add_node(84);
//     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 84 DE LL" << std::endl;
//     a.showmeLL();

//    a.add_node(25);
//     std::cout<<"\n\n\n MOSTRANDO LOS ELEMENTOS CON 25 DE LL" << std::endl;
//     a.showmeLL();

    // showLL(a);
    // CHQUEANDO SI UN DATO EXISTE
    // a.exist(25);

    return 0;
}