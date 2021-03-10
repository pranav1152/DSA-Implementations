/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Pairs with create,insert,delete.
   Stay Focused!
*/

#include <iostream>
#include <utility> 		// Header file for pairs.
using namespace std;

int main() {

	// Diffrent types of initialization with declaration.
	pair<int, char> p1; 		// Default empty pair.
	pair<int, char> p2(1, 'a'); // Value initialization.
	pair<int, char> p3(p2); 	// Copy of pair p2.

	// Another way to initialize pairs:
	p1 = make_pair(2, 'b');

	//Accessing pair elements:
	cout << p2.first() << " " << p2.second() << endl;

	// Operators(=,==,!=,>=,<=) can be used for pairs.Uses first element to compair.
	pair<int, int> pair1 = make_pair(1, 12);
	pair<int, int> pair1 = make_pair(9, 12);

	cout << (pair1 == pair2) << endl;
	cout << (pair1 != pair2) << endl;
	cout << (pair1 >= pair2) << endl;
	cout << (pair1 <= pair2) << endl;

	// Swapping 2 pairs:
	pair1.swap(pair2);
	cout << pair1.first() << " " << pair1.second() << endl;
	cout << pair2.first() << " " << pair2.second() << endl;

	return 0;
}
