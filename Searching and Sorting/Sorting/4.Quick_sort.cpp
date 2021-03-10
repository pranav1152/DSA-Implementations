/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Sorting with Acending order.
   			Basic intuation is choose first element as pivot. Place pivot at it's position.
   			Call recursively on smaller part of array and partion array accordingly.
   Date:    31/08/2020.
   Stay Focused!
*/

#include "bits/stdc++.h"
using namespace std;

#define IOS			ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

int partitionArray(int input[], int start, int end) {
// Chose pivot
	int pivot = input[start];
// Count elements smaller than pivot and swap
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (input[i] <= pivot) {
			count++;
		}
	}
	int pivotIndex = start + count;
	int temp = input[start];
	input[start] = input[pivotIndex];
	input[pivotIndex] = temp;
	// ensure left half contains elements smaller than pivot
	// and right half larger
	int i = start, j = end;
	while (i <= pivotIndex && j >= pivotIndex) {
		while (input[i] <= pivot) {
			i++;
		}
		while (input[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp; i++;
			j--;
		}
	}
	return pivotIndex;
}

void quickSort(int input[], int start, int end) {
	if (start >= end) {
		return;
	}
	int pivotIndex = partitionArray(input, start, end);
	quickSort(input, start, pivotIndex - 1);
	quickSort(input, pivotIndex + 1, end);
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
	// We always pass indices to quickSort function.
	quickSort(elements, 0, n - 1);
	cout << "Sorted elements are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}
	delete[] elements;
	return 0;
}
