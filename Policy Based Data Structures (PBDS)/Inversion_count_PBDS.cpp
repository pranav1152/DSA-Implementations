/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Solution of inversion count using PBDS.
   Date	  : 21/09/2020
   Stay Focused!
*/

#include "bits/stdc++.h"

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        PBDS;

int main() {

	// distinct case

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	PBDS St;

	int inversion_count = 0;

	for (int i = 0; i < n; i++) {
		inversion_count += (St.size() - St.order_of_key(a[i]));
		St.insert(a[i]);
	}

	cout << inversion_count;

	// leetcode
	// hackerrank
	// codechef
	// codechef

}