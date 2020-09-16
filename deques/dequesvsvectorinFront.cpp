/* Lecture Code 2.3
 *
 * Time trial of vector vs deque for the push_front (or insert(container.begin())) functions.
 * Refer to Lecture Code 2.1 for more information.
 */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
using namespace std;

const size_t kNumElems = 10000;
const size_t kNumTests = 100;

void RunVectorTest() {
	
	clock_t start = clock();
	vector<int> myContainer;

	for(size_t h = 0; h < kNumTests; h++) {
		for(size_t i = 0; i < kNumElems; i++)
			myContainer.insert(myContainer.begin(), i);
		for(size_t h = 0; h < kNumElems; h++)
			myContainer.erase(myContainer.begin());
	}

	start = clock() - start;

	cout << "Vector finished in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

void RunDequeTest() {
	
	clock_t start = clock();
	deque<int> myContainer;

	for(size_t h = 0; h < kNumTests; h++) {
		for(size_t i = 0; i < kNumElems; i++)
			myContainer.push_front(i);
		for(size_t h = 0; h < kNumElems; h++)
			myContainer.pop_front();
	}

	start = clock() - start;

	cout << "Deque finished in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

int main() {
     std::cout<<"\n>PRUEBA PARA EL VECTOR  ASIGNANDO EN EL FRENTE..\n\n";
	RunVectorTest();
     std::cout<<"\n>PRUEBA PARA EL DEQUE ASIGNANDO EN EL FRENTE..\n\n";
	RunDequeTest();
    cout << endl;

	return 0;
}