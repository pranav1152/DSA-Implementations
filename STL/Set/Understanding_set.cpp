/* Author :  		Pranav Deshmukh
            		PICT,Pune
   Purpose: 		Understanding set(Ordered);for unordered set functions elements are not
   					stored in order and internal implementation is diffrent.
   Time Complexity: For Ordered Set:
   					[1] insert() -> O(log n)
   					[2] find()   -> O(log n)
   					[3] size()   -> O(1)
   					[4] erase()  -> O(1)          For one element.

   					For Unordered Set:
   					[1] insert() -> O(1)		  Average
   					             -> O(n)          Worst Case
   					[2] find()   -> O(1)		  Average
   					             -> O(n)          Worst Case
   					[3] size()   -> O(1)
   					[4] erase()  -> O(1)		  Average
   					             -> O(n)          Worst Case          For one element.
   Ordered Set in STL is implemented using balanced binary tree.
   Unordered Set in STL is implemented using hashing.
   Stay Focused!
*/

#include <iostream>
#include <set>
using namespace std;

int main() {

	// Creating set
	set<int> s1;								//Empty Set
	int a[] = {1, 2, 3, 4, 5, 5};
	set<int> s2(a, a + 6);						//s2 = {1,2,3,4,5}
	set<int> s3(s2);							//Copy of s2.
	set<int> s4(s3.begin(), s3.end());			//Set creation using iterators.
	set<int> s;
	for (int i = 0; i < 7; i++) {
		s.insert(i + 1);
	}

	// Iterating over set
	set<int> :: iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// Iterating with for-each loop
	for (auto no : s) {
		cout << no << " ";
	}
	cout << endl;

	// Delete an element
	s.erase(2);

	// Find an element
	auto searched = s.find(2);
	if (searched != s.end())
		cout << "exists" << endl;
	else
		cout << "2 does not exists" << endl;

	// Size of set
	cout << "size of set is " << s.size() << endl;

	// Delete all elements of set
	s.clear();

	// Check wheteher set is empty or not
	if (s.empty())
		cout << "Set is empty" << endl;
	else
		cout << "Set is not empty" << endl;

	return 0;
}
