/* Author :       Pranav Deshmukh
                  PICT,Pune
   Purpose:       Understanding Dynamic Programming.
   Stay Focused!
*/

#include <iostream>
#include <chrono>	    //For time taken by each function.
using namespace std;
using namespace std::chrono;


int lcsBruteForce(string s, string t) {
	// Base case
	if (s.size() == 0 || t.size() == 0) {
		return 0;
	}

	// Recursive calls
	if (s[0] == t[0]) {
		return 1 + lcsBruteForce(s.substr(1), t.substr(1));
	}
	else {
		int a = lcsBruteForce(s.substr(1), t);
		int b = lcsBruteForce(s, t.substr(1));
		int c = lcsBruteForce(s.substr(1), t.substr(1));
		return max(a, max(b, c));
	}
}

int lcsMemoization(string s, string t, int** ans) {
	if (s.size() == 0 || t.size() == 0) {
		return 0;
	}

	int m = s.size();
	int n = t.size();

	if (ans[m][n] != -1) {
		return ans[m][n];
	}
	if (s[0] == t[0]) {
		ans[m - 1][n - 1] = lcsMemoization(s.substr(1), t.substr(1), ans);
		ans[m][n] = 1 + ans[m - 1][n - 1];
	}
	else {
		ans[m][n - 1] = lcsMemoization(s, t.substr(1), ans);
		ans[m - 1][n] = lcsMemoization(s.substr(1), t, ans);
		ans[m][n] = max(ans[m][n - 1], ans[m - 1][n]);
	}

	return ans[m][n];
}

int lcsMemoization(string s, string t) {
	int** ans = new int*[s.size() + 1];
	for (int i = 0; i < s.size() + 1; i++) {
		ans[i] = new int[t.size() + 1];
		for (int j = 0; j < t.size() + 1; j++) {
			ans[i][j] = -1;
		}
	}
	int ansr = lcsMemoization(s, t, ans);
	for (int i = 0; i < s.size() + 1; i++) {
		delete[] ans[i];
	}
	delete[] ans;
	return ansr;
}

int lcsDynamicProgramming(string s, string t) {
	int m = s.size();
	int n = t.size();
	int** ans = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		ans[i] = new int[n + 1];
	}

	// First row
	for (int j = 0; j <= n; j++) {
		ans[0][j] = 0;
	}

	// First col
	for (int i = 0; i <= m; i++) {
		ans[i][0] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[m - i] == t[n - j]) {
				ans[i][j] = 1 + ans[i - 1][j - 1];
			}
			else {
				ans[i][j] = max(ans[i - 1][j] , ans[i][j - 1]);
			}
		}
	}
	return ans[m][n];
}

int main() {
	string s, t;
	//cin >> s >> t;
	// Time Taken will work wll when input is inbuild.
	s = "fdhbhdbv" ;
	t = "sedvkbdf";
	// Dynamic Programming
	auto start = high_resolution_clock::now();
	cout << "Answer by Dynamic Programming:" << lcsDynamicProgramming(s, t) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cerr << "Time taken by Dynamic Programming in microseconds:" << duration.count() << endl;

	// Memoization
	start = high_resolution_clock::now();
	cout << "Answer by Memoization:" << lcsMemoization(s, t) << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cerr << "Time taken by Memoization in microseconds:" << duration.count() << endl;

	// Brute Force
	start = high_resolution_clock::now();
	cout << "Answer by Brute Force Recursion:" << lcsBruteForce(s, t) << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cerr << "Time taken by Brute Force Recursion:" << duration.count() << endl;

	return 0;
}
