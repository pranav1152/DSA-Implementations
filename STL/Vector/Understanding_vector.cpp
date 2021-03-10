/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Vectors with create,insert,delete.
   Stay Focused!
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n = 10;
	vector<int> v1;
	//Creates empty vector of integers.

	vector<int> v2(5, 10);
	//Creates five integers with value 10.

	vector<int> v3(v2.begin(), v2.end());
	//Creates vector with vector elements [v.begin(),v.end()).

	int* arr = new int[n];

	vector<int> v4(arr, arr + n);
	//Creates vector with array elements [arr,arr+n).

	vector<int> v5(v3);
	//Makes copy of vector v3;

	vector<int> v(3, 5);
	cout << v.at(4) << endl; 	// Error heance safer to use. -> O(1) TC
	cout << v[4] << endl;		// Garbage Value.			  -> O(1) TC
	// Use [] for getting and setting value only not for setting value.
	v.push_back(5); // Insert new element at end of vector.   -> O(1) TC
	v.clear();       // Deletes all elements and assign an empty vector. -> O(n) TC

	vector<int>* vp = new vector<int>(); // Dynamic allocation of vector.

	cout << v.empty() << endl; // Returns true if empty and false if not. -> O(1) TC

	vector<int> :: iterator itr; // Declaring vector iterator.

	for (itr = v2.begin(); itr != v2.end(); itr++) {
		cout << *itr << " ";	// Iterator contains address.
	}
	// Iterating vector through iterator.
	// Iterator can also initialized as :
	auto itr2 = v2.begin();

	v2.pop_back(); // Removes last element from vector. -> O(1) TC
	return 0;
}
