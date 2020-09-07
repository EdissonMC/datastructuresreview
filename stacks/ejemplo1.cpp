/* Lecture Code 2.0
 *
 * Basic use of the STL stack type.
 */

#include <iostream>
#include <stack>
using namespace std;

const int NUM_INTS = 10;

int main() {
	stack<int> myStack;

	for(int i = 0; i < NUM_INTS; i++)
		myStack.push(i);

	cout << "The size is " << myStack.size() << endl;
	cout << "The top element is " << myStack.top() << endl;
	
	while(!myStack.empty()) {
		cout << myStack.top() << ' ';
		myStack.pop();
	}

	cout << endl;
	
	return 0;
}

