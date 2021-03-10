/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Searching Basics.Used for Sorted array.
   Date:    29/08/2020.
   Stay Focused!
*/

#include <iostream>
using namespace std;

#define IOS         ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

int binarySearchRecursive(int arr[], int start, int end, int x) {
  int mid = start + ((end - start) / 2);
  if (start > end)
    return -1;
  if (arr[mid] == x)
    return mid;
  else if (arr[mid] > x)
    return binarySearchRecursive(arr, start, mid - 1, x);
  else
    return binarySearchRecursive(arr, mid + 1, end, x);
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
  int toFind;
  cout << "Enter element to be found:" << endl;
  cin >> toFind;
  int idx = binarySearchRecursive(elements, 0, n - 1, toFind);
  if (idx != -1)
    cout << "Element is at index:" << idx << endl;
  else
    cout << "Element not found" << endl;
  delete[] elements;
  return 0;
}