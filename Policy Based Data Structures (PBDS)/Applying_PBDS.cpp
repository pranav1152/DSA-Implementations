/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Application of PBDS.
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        PBDSP;

int main() {
	PBDS St;
	St.insert(15);
	St.insert(3);
	St.insert(4);
	St.insert(10);
	St.insert(1);

	// kth largest element at till now (logn)
	for (int i = 0; i < St.size(); i++) {
		cout << i << " " << *St.find_by_order(i) << '\n';
	}

	cout << "Order of key 5 is " << St.order_of_key(5) << endl;

	// To store multiple keys
	PBDSP Stm;
	// {value,index}
	Stm.insert({15, 0});
	Stm.insert({3, 1});
	Stm.insert({10, 2});
	Stm.insert({4, 3});
	Stm.insert({1, 4});
	Stm.insert({1, 5});

	cout << endl;

	cout << "Key value pair : " << endl;

	// kth largest element at till now (logn)
	for (int i = 0; i < Stm.size(); i++) {
		cout << i << " " << Stm.find_by_order(i)->first << " " << Stm.find_by_order(i)->second << '\n';
	}
}