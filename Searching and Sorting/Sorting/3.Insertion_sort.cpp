/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding Sorting with Acending order.
   			Maintain sorted and unsorted part of array.Traverse array, keep element at it's correct
   			position in sorted array.This is similar to sort cards in card game.
   Date:    31/08/2020.
   Stay Focused!
*/

#include "bits/stdc++.h"
using namespace std;

#define IOS			ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
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
	insertionSort(elements, n);
	cout << "Sorted elements are : " << endl;
	for (int i = 0; i < n; i++) {
		cout << elements[i] << " ";
	}
	delete[] elements;
	return 0;
}
