/* Author : 			Pranav Deshmukh
           				PICT,Pune
   Problem statement :

						On a positive integer, you can perform any one of the following 3 steps.

						Subtract 1 from it. ( n = n - 1 )
						If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2 )
						If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3 ).
   Stay Focused!
*/
#include <iostream>
#include <limits.h>
#include <chrono>	    //For time taken by each function.
using namespace std;
using namespace std::chrono;

int minStepsBruteForce(int n) {
	// Base Case
	if (n == 1)
		return 0;

	int x = minStepsBruteForce(n - 1);
	int y = INT_MAX, z = INT_MAX;

	if (n % 2 == 0)
		y = minStepsBruteForce(n / 2);
	if (n % 3 == 0)
		z = minStepsBruteForce(n / 3);

	return min(x, min(y, z)) + 1;
}

int minStepsMemoization(int n, int* ans) {
	if (n == 1) {
		ans[n] = 0;
		return 0;
	}

	if (ans[n - 1] == -1) {
		ans[n - 1] = minStepsMemoization(n - 1, ans);
	}
	int y = INT_MAX, z = INT_MAX;
	if (n % 2 == 0) {
		if (ans[n / 2] == -1) {
			ans[n / 2] = minStepsMemoization(n / 2, ans);
		}
		y = ans[n / 2];
	}
	if (n % 3 == 0) {
		if (ans[n / 3] == -1) {
			ans[n / 3] = minStepsMemoization(n / 3, ans);
		}
		z = ans[n / 3];
	}
	ans[n] = min(ans[n - 1], min(y, z)) + 1;
	return ans[n];

}

int minStepsMemoization(int n) {
	// Helper function for user overloaded.
	int* ans = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	int vreturn = minStepsMemoization(n, ans);
	delete[] ans;
	ans = NULL;
	return vreturn;
}

int minStepsDP(int n) {
	int* ans = new int[n + 1];
	ans[1] = 0;

	for (int i = 2; i <= n; i++) {
		int x = ans[i - 1], y = INT_MAX, z = INT_MAX;
		if (i % 2 == 0)
			y = ans[i / 2];
		if (i % 3 == 0)
			z = ans[i / 3];
		ans[i] = min(x, min(y, z)) + 1;
	}

	return ans[n];
}

int main() {
	int n;
	cout << "Enter Number:" << endl;
	cin >> n;

	// Memoization
	auto start = high_resolution_clock::now();
	cout << "Answer by Memoization:" << minStepsMemoization(n) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by Memoization:" << duration.count() << endl;

	// Dynamic Programming
	start = high_resolution_clock::now();
	cout << "Answer by Dynamic Programming:" << minStepsDP(n) << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by Dynamic Programming:" << duration.count() << endl;

	// Brute Force
	start = high_resolution_clock::now();
	cout << "Answer by Brute Force Recursion:" << minStepsBruteForce(n) << endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by Brute Force Recursion:" << duration.count() << endl;

	return 0;
}
