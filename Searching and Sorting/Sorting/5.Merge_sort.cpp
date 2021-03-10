/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Sorting with Acending order.
   			Basic intuation is make two sorted array with the help of recursion.Merge them with help
   			of comparision.This is divide and conquer type algorithm.
   Date:    31/08/2020.
   Stay Focused!
*/

#include "bits/stdc++.h"
using namespace std;

#define IOS			ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

void merge(int arr[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; 				// Initial index of first subarray
	j = 0; 				// Initial index of second subarray
	k = left; 			// Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k++] = L[i++];
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k++] = R[j++];
	}
}

// left is for left index and right is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int left, int right)
{
	if (left < right) {
		// To avoid overflow
		int m = left + (right - left) / 2;

		mergeSort(arr, left, m);
		mergeSort(arr, m + 1, right);

		merge(arr, left, m, right);
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
	// We always pass indices to mergeSort function.
	mergeSort(elements, 0, n - 1);
	cout << "Sorted elements are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}
	delete[] elements;
	return 0;
}
