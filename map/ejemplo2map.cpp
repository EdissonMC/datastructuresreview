/* Lecture Code 4.5
 *
 * Basic STL map usage.
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	/* STL maps require two arguments - the type of the keys
	 * and the type of the values.  This map is akin to the
	 * CS106B/X Map<int>.
	 */
	map<string, int> myMap;

	/* One way of inserting values is to use the insert
	 * function, which takes in a key/value pair and adds
	 * it to the map.
	 */
	myMap.insert(make_pair("STL", 137));
	myMap.insert(make_pair("IS", 42));
	myMap.insert(make_pair("AWESOME", 2718));
	
	/* Alternatively, you can use the bracket operators to
	 * select elements.
	 */
	myMap["AWESOME"] = 271828;
	
	/* Remove the key IS from the map. */
	myMap.erase("IS");

	/* Use find() to check whether STL is a key in the map.
	 * We could also use count() if we were so inclined.
	 */
	if(myMap.find("STL") != myMap.end())
		cout << "The STL exists." << endl;

	/* Use iterators to print out each key/value pair.  Note that map
	 * iterators act as though they iterate over pair<Key, Value>s.
	 */
	for(map<string, int>::iterator itr = myMap.begin(); itr != myMap.end(); ++itr) {
		/* The syntax itr->first or itr->second means "select the
		 * field 'first' or field 'second' from the pair."  The rationale
		 * behind this is explained in the course reader.
		 */
		cout << "Key: " << itr->first << ", Value: " << itr->second << endl;
	}
}