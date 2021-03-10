/* Author : Pranav Deshmukh 
            PICT,Pune
   Stay Focused!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter Number:" << endl;
	cin >> n;
	// Check 0th bit
	if (n & 1 == 0)
		cout << "Even" << endl;
	else
		cout << "Odd" << endl;
	return 0;
} 
