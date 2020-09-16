/* Lecture Code 2.4
 *
 * Time trial of vector vs deque for element access.
 * Refer to lecture code 2.1 for more information.
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
	ContainerType myContainer(kNumElems);

	for(size_t h = 0; h < kNumTests; h++) {
		for(size_t i = 0; i < kNumElems; i++)
			myContainer[i] = i;
	}

	start = clock() - start;

	cout << "Test completed in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

int main() {
    std::cout<<"\n>PRUEBA PARA EL VECTOR  ACCEDIENDO A LOS ELEMENTOS ..\n\n";
	RunTest< vector<int> >();
    
    
    std::cout<<"\n>PRUEBA PARA EL DEQUE  ACCEDIENDO A LOS ELEMENTOS ..\n\n";
	RunTest< deque<int> >();

	return 0;
}


/*
Spaceflight → 
Communications satellite → 
Broadband → 
National Broadband Plan (United States) → 
Comcast
*/