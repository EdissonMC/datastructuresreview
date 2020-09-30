#include <iostream>
#include <string>


/*

    FILE : BeaconsOfGonder.cpp
    __________________________
    This program illustrates the concept of a linked list by simulating the 
    Beacons of Gondor story from J.  R. R. Tolkiends Return of the King.

*/


/*
    Type: Tower
    __________
    This structure contains the name of the tower and a link to the next one

*/

struct  Tower
{
   
    std::string name;     /* The name of this tower */
    Tower *link;          /* Pointer to the next tower in the chain */

};



/*  Function prototypes  */

Tower *createBeaconsOfGondor();
Tower *createTower(std::string name, Tower *link) ;
void signalWithFor(Tower *start);
void signalRecursion( Tower *start);

int main () {

    Tower *list = createBeaconsOfGondor ();
    //signalWithFor(list);
    signalRecursion(list);

    return 0;
}


/*

    Function: createBeaconsOfGondor
    Usage: Tower  *list = createBeaconsOfGondor();
    ______________________________________________
    Creates  a linked list of the towers described by Tolkien.
    The function builds the list backwards and returns a pointer to the first tower

*/

Tower  *createBeaconsOfGondor () {

    Tower *tp = createTower("Rohan",  NULL);
    
    tp  = createTower("Halifirien",  tp);
    tp  = createTower("Calenhad",    tp);
    tp  = createTower("Min-Rimmon",  tp);
    tp  = createTower("Erelas",  tp);
    tp  = createTower("Nardol",  tp);
    tp  = createTower("Eilenach",  tp);
    tp  = createTower("Amon Din",  tp);
    
    return createTower("Minas Tirith",  tp);
    

}

/*
    Function : createTower
    Usage : Tower *chain = createTower(name,  link);
    ________________________________________________
    Creates a new Tower structure with the specified components
*/


Tower *createTower(std::string name, Tower *link) {

    Tower *tp =  new Tower;
    tp->name  =  name;
    tp->link  =  link;
    return tp;

}


void signalWithFor (Tower *start) {

    for (Tower  *tp = start;  tp != NULL;  tp= tp->link) {
        std::cout <<"ligthting" << tp->name << std::endl;
    }

}


void signalRecursion( Tower *start) {

    if(start != NULL) {
        std::cout <<"Lighting" << start->name << std::endl;
        signalRecursion(start->link);
    }
}


