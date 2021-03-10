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
	if ((n & (n - 1)) == 0)
		cout << "Power of 2" << endl;
	else
		cout << "Not power of 2" << endl;
	return 0;
}
