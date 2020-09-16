/* Lecture code 6.2
 *
 * Set algorithms.  Demonstrates set_union, ostream_iterator,
 * inserter.
 */

#include <iostream>
#include <set>
#include <iterator>  // For ostream_iterator, inserter.
#include <algorithm> // copy, set_union
using namespace std;

const int kNumInts = 10;

int main() {
	set<int> evens, odds;
	for(int i = 0; i < kNumInts; ++i) {
		evens.insert(i * 2);
		odds.insert(i * 2 + 1);
	}
	
	/* Take the union. */
	set<int> result;
	set_union(evens.begin(), evens.end(), odds.begin(), odds.end(),
		  inserter(result, result.begin()));
	
	/* Print to cout. */
	copy(result.begin(), result.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}