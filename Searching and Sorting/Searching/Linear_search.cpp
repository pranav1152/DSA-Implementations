/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Searching Basics.Used for unsorted array.
   Date:    29/08/2020.
   Stay Focused!
*/

#include <iostream>
using namespace std;

#define int 				long long
#define IOS					ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

int linearSearch(int arr[], int N, int X)
{
	// Start traversing the array
	for (int i = 0; i < N; i++)
	{
		// If a successful match is found,
		// return the index
		if (arr[i] == X)
			return i;
	}

	// If the element is not found and end of array is reached,
	return -1;
}

int32_t main() {
	IOS;
	int n;
	cout << "Enter total number of elements:" << endl;
	cin >> n;
	cout << "Enter elements:" << endl;
	int* elements = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	int toFind;
	cout << "Enter element to be found:" << endl;
	cin >> toFind;
	int idx = linearSearch(elements, n, toFind);
	if (idx != -1)
		cout << "Element is at index:" << idx << endl;
	else
		cout << "Element not found" << endl;
	delete[] elements;
}