/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Undersatnding String Algorithms from scratch.
   Date	  : 03/09/2020
   Stay Focused!
*/

#include <iostream>
using namespace std;

bool isMatching(string s, string p) {

	int n = s.length();
	int m = p.length();

	for (int i = 0; i <= (n - m); i++) {
		bool isFound = true;
		for (int j = 0; j < m; j++) {
			if (s[i + j] != p[j]) {
				isFound = false;
				break;
			}
		}
		if (isFound == true)
			return true;
	}
	return false;
}

int main() {

	string s;
	string p;
	cin >> s >> p;
	cout << isMatching(s, p) << endl;
	return 0;
}