/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	cout << "Enter number followed by ith(from 0) bit place:" << endl;
	cin >> n >> i;
	int m = ~((1 << (i + 1)) - 1);
	n = n & m;
	cout << "Answer is " << n << endl;
	return 0;
}