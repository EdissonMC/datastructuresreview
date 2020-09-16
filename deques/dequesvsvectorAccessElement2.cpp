/* Lecture Code 2.5
 *
 * Time trial of vector vs deque for element access.  However, this time the container is declared inside
 * the outer loop, which has a major performance hit for the deque.
 * Refer to Lecture Code 2.1 for more information.
 */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
using namespace std;

const size_t kNumElems = 100000;
const size_t kNumTests = 1000;

template <typename ContainerType> void RunTest() {
	
	clock_t start = clock();
     int aleatorio =rand()% kNumElems;

	for(size_t h = 0; h < kNumTests; h++) {
		ContainerType myContainer(kNumElems);
		for(size_t i = 0; i < kNumElems; i++)
			myContainer[aleatorio] = i;
	}

	start = clock() - start;

	cout << "Test completed in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

int main() {

    // Use current time as seed for random generator 
    srand(time(0));
    // int aleatorio =rand()%5;
    // std::cout << aleatorio;
    
    std::cout<<"\n>ESTA PRUEBA SE HACE REDECLARANDO EL CONTENEDOR CADA VEZ QUE INGRESA AL LOOP..\n\n";
	

    std::cout<<"\n>PRUEBA PARA EL VECTOR  ACCEDIENDO A LOS ELEMENTOS ..\n\n";
	RunTest< vector<int> >();
    std::cout<<"\n>PRUEBA PARA EL DEQUE  ACCEDIENDO A LOS ELEMENTOS ..\n\n";
	RunTest< deque<int> >();

	return 0;
}