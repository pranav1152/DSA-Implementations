/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Understanding segment tree with build,modify,delete functions.
   	    Here Find sum of elements between interval is implemented.
   Date   : 27/08/2020.
   Stay Focused!
*/

#include <iostream>
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
	if (start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;

	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int* arr, int* tree, int start, int end, int treeNode, int idx, int value) {
	if (start == end) {
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (idx > mid) {
		updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
	}
	else {
		updateTree(arr, tree, start, mid, 2 * treeNode, idx, value);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int* tree, int start, int end, int treeNode, int left, int right) {

	// Completely outside given range
	if (start > right || end < left) {
		return 0;
	}

	// Completely inside given range
	if (start >= left && end <= right) {
		return tree[treeNode];
	}

	// Partially inside and partially outside
	int mid = (start + end) / 2;
	int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
	int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	return ans1 + ans2;
}

int main() {

	int n;
	cout << "Enter size of array:" << endl;
	cin >> n;
	int* arr = new int[n];
	cout << "Enter array elements:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Always take size of segment tree as 4*n.
	int* tree = new int[4 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	cout << "Segment tree is builded" << endl;
	cout << "Enter index and value to be updated respectively:" << endl;
	int idx, val;
	cin >> idx >> val;

	updateTree(arr, tree, 0, n - 1, 1, 2, 10);
	cout << "Tree is updated sucessfully" << endl;

	cout << "Enter interval range(indices) in which sum is required: " << endl;
	int l, r;
	cin >> l >> r;
	int ans = query(tree, 0, n - 1, 1, l, r);
	cout << "Sum in given interval is : " << ans << endl;

	// Deleting allocated memory:
	delete[] arr;
	delete[] tree;
	return 0;
}


/*  Example :
    5 1 2 3 4 5 2 10 2 4
	arr[] = {1, 2, 3, 4, 5};
*/
