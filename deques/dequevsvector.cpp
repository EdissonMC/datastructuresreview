

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
using namespace std;

/* Lecture Code 2.2
    
    Time trial of the deque against the vector using the push_back function.
    Refer to Lecture Code 2.1 for information on the tricky syntax.
 
 */

const size_t kNumElems = 100000;
const size_t kNumTests = 500;



template <typename ContainerType> void RunTest() {
	
	clock_t start = clock();
	ContainerType myContainer;

	for(size_t h = 0; h < kNumTests; h++) {

		for(size_t i = 0; i < kNumElems; i++)
			myContainer.push_back(i);
		
        for(size_t h = 0; h < kNumElems; h++)
			myContainer.pop_back();
	}

	start = clock() - start;

	cout << "Test completed in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

int main() {
    std::cout<<"\n>PRUEBA PARA EL VECTOR..\n\n";
	RunTest< vector<int> >();

    std::cout<<"\n>PRUEBA PARA EL DEQUE...\n\n";
	RunTest< deque<int> >();
    std::cout<<std::endl;
	return 0;
}