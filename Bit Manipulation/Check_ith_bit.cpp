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
	if (n  & 1 << i) {
		cout << "Bit is Set" << endl;
	}
	else {
		cout << "Bit is not Set" << endl;
	}
	return 0;
}