/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding algorithms implementation in C++ with sort,binary search,lower bound,upper bound,
   			GCD,power,swap,maximum and minimum function.
   Stay Focused!
*/

#include <iostream>
#include <algorithm>					// Header file for including STL algorithms
#include <cmath>						// For power function
#include <utility>						// For swapping two elements
using namespace std;

int main() {

	// Sort Function
	// Sort in increasing order
	int arr[] = {1, 3, 2, 6, 5, 4};
	sort(arr, arr + 6);
	// Sort subarray
	sort(arr + 2, arr + 6);
	// Sort in decreasing order
	sort(arr, arr + 6, greater<int>());
	
	// Sort vector
	sort(v.begin(),v.end(),greater<int>());

	// Binary Search
	// Must be done on sorted array.
	// Returns boolean value(1 or 0).
	sort(arr, arr + 6);
	binary_search(arr, arr + 6, 3);

	// Lower Bound
	// It returns pointer to position if found(first occurence).
	// Otherwise it returns just high number greater than which is to be searched.
	// The elements in the range shall already be sorted or at least partitioned with respect to val.
	cout << *lower_bound(arr, arr + 6, 3) << " is lower bound of 3 at " << lower_bound(arr, arr + 6, 3) - arr << endl;

	// Upper bound
	// Returns pointer to next number which is to be searched.
	// The elements in the range shall already be sorted or at least partitioned with respect to val.
	cout << *upper_bound(arr, arr + 6, 3) << " is lower bound of 3 at " << lower_bound(arr, arr + 6, 3) - arr << endl;

	// GCD of two numbers
	cout << "gcd(6, 20) = " << __gcd(6, 20) << endl;

	// Power function
	cout << "2 to power 3 is " << pow(2, 3) << endl;

	// Swap function
	string s1 = "abc", s2 = "xyz";
	swap(s1, s2);
	cout << s1 << " " << s2 << endl;

	// Maximum Function
	cout << max(14, 18) << endl;

	// Minimum Function
	cout << min(14, 18) << endl;
	return 0;
}
