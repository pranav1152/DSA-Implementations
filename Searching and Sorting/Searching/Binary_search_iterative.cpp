/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Searching Basics.Used for Sorted array.
   Date:    29/08/2020.
   Stay Focused!
*/

#include <iostream>
using namespace std;

#define int                         long long
#define IOS                         ios_base::sync_with_stdio(0); cin.tie(0) ; cin.tie(0)

int binarySearchIterative(int arr[], int N, int K) {
  int start = 0, end = N - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (arr[mid] == K)
      return mid;

    else if (K > arr[mid])
      start = mid + 1;

    else
      end = mid - 1 ;
  }
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
  int idx = binarySearchIterative(elements, n, toFind);
  if (idx != -1)
    cout << "Element is at index:" << idx << endl;
  else
    cout << "Element not found" << endl;
  delete[] elements;
}