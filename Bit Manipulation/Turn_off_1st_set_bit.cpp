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
	n = n & (n - 1) ;
	cout << "Number is " << n << endl;
	return 0;
}