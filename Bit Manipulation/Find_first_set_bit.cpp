/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter Number:" << endl;
	cin >> n;
	n = n & (-1 * n);
	cout << "Number with set bit is " << n << endl;
	return 0;
}