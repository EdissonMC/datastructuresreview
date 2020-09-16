/* Lecture Code 4.3
 *
 * The set's lower_bound and upper_bound functions, which select
 * elements in a bounded range.
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
	/* Create a set and populate it with many multiples of
	 * five.
	 */
	set<int> mySet;
	for (size_t i = 0; i < kNumValues; i++)
		mySet.insert(i * 5);

	/* Use lower_bound and upper_bound to select all of the elements
	 * in the set in the range [27, 43].  Note that this loop is
	 * slightly inefficient; see below for a better option.
	 */
	for (set<int>::iterator itr = mySet.lower_bound(27); itr != mySet.upper_bound(43); ++itr)
		cout << *itr << ' ';
	cout << endl;
	
	/* A more efficient version of the above loop that caches the value of
	 * mySet.upper_bound(43).
	 */
	for (set<int>::iterator itr = mySet.lower_bound(27), stop = mySet.upper_bound(43);
	     itr != stop; ++itr)
		cout << *itr << ' ';
	cout << endl;
}