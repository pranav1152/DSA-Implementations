/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose :Understanding DP
   Stay Focused!
*/
#include <bits/stdc++.h>
using namespace std;

int fibmemo(int n, int* dp) {
	if (n <= 1) {
		dp[n] = n;
		return n;
	}
	if (dp[n - 1] == 0) {
		dp[n - 1] = fibmemo(n - 1, dp);
	}
	if (dp[n - 2] == 0) {
		dp[n - 2] = fibmemo(n - 2, dp);
	}
	dp[n] = dp[n - 1] + dp[n - 2];
	return dp[n];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int* dp = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	cout << fibmemo(n, dp) << endl;
	return 0;
}
