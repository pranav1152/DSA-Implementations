/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose :Understanding DP
   Stay Focused!
*/
#include <bits/stdc++.h>
using namespace std;

int fibnormal(int n) {
	if (n <= 1)
		return n;
	return fibnormal(n - 1) + fibnormal(n - 2);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cout << fibnormal(n) << endl;
	return 0;
}
