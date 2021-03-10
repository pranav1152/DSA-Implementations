/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Undersatnding Fast Exponentiation using bitmasking.
   Date	  : 15/10/2020
   Stay Focused!
*/

#include <iostream>
using namespace std;
#define ll		long long

ll fastModExp(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a);
		}
		a = a * a;
		b = b >> 1;
	}
	return res;
}


int main() {

	cout << fastModExp(5, 3);
	return 0;
}