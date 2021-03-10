/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose :Understanding DP
   Stay Focused!
*/
#include<bits/stdc++.h>
using namespace std;

int fibDP(int n) {
	int* DP = new int[n + 1];
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	return DP[n];
}

int main() {
	int n;
	cin >> n;
	cout << fibDP(n) << endl;
	return 0;
}