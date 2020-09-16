/* Lecture Code 4.1
 *
 * Basic STL set usage.
 */
#include <iostream>
#include <set>
using namespace std;

/* Constant: kNumValues
 * -------------------------------------------------
 * The number of elements to insert into the set.
 */
const size_t kNumValues = 10;

int main() {
	/* Create a set and populate it with values. */
	set<int> mySet;
	for(size_t i = 0; i < kNumValues; i++)
		mySet.insert(i); // Add i to the set

    /* Showing original set*/
    std::cout << "\n\nMOSTRANDO EL SET ORIGINAL\n";
    for(set<int>::iterator itr = mySet.begin(); itr != mySet.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;


	/* Check whether 5 exists in the set.  We could have
	 * alternatively written
	 *
	 *    if (mySet.count(5))
	 *
	 * instead of using find() and end().
	 */
    std::cout << "\n>VERIFICANDO SI EL #5 ESTA EN EL SET\n";
	if(mySet.find(5) != mySet.end())
		cout << "The set contains five." << endl;

    
  
	/* Remove the element 4 from the set. */
    std::cout << "\n>BORRANDO EL NUMERO 4 EN EL SET\n";
	mySet.erase(4);
	


	/* Print out how many elements are contained in the set. */
	cout << "\nNow the set contains ";
	cout << mySet.size() << " elements." << endl;
    



	/* Use iterators to print out the contents of the set. */
     std::cout << "\n>MOSTRANDO EL SET DESPUES DE BORRAR EL NUMERO 4\n";
	for(set<int>::iterator itr = mySet.begin(); itr != mySet.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;
}