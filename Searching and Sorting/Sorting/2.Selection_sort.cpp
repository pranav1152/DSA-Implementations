/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Sorting with Acending order.
   			Basic intuation is, in each iteration pick minimum element and place it in
   			its right position.
   Date:    31/08/2020.
   Stay Focused!
*/

#include "bits/stdc++.h"
using namespace std;

#define IOS			ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr[min_idx], arr[i]);
	}
}

int main() {
	IOS;
	int n;
	cout << "Enter total number of elements:" << endl;
	cin >> n;
	cout << "Enter elements:" << endl;
	int* elements = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	selectionSort(elements, n);
	cout << "Sorted elements are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}
	delete[] elements;
	return 0;
}
