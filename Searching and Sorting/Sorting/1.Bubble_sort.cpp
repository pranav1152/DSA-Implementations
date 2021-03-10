/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Sorting with Acending order.
   			Basic intuation is 2 loops. At the end of each inner loop largest element of unsorted,
   			array part will be at its correct position. Algorithm intuative to boiling water.
   Date:    31/08/2020.
   Stay Focused!
*/

#include "bits/stdc++.h"
using namespace std;

#define IOS			ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

void bubbleSortOptimised(int arr[], int n) {
	/*
		Two Optimisations: [1] At end of each loop last element is droped from checking.
						   [2] If array is already sorted only one iteration of loop takes place.
	*/
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!(swapped)) {
			break;
		}
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
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
	bubbleSortOptimised(elements, n);
	cout << "Sorted elements are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}
	delete[] elements;
	return 0;
}
