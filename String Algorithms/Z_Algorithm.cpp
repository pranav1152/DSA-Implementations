/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/
#include <iostream>
using namespace std;

void buildZ(int* Z, string str) {
	int l = 0;
	int r = 0;

	int n = str.length();
	for (int i = 1; i < n; i++) {
		if (i > r) {
			// i does not lie between l and r.
			// Z for this doesn't exists.
			l = i;
			r = i;
			while (r < n && str[r - l] == str[r]) {
				r++;
			}
			Z[i] = r - l;
			r--;
		} else {
			int k = i - l;
			if (Z[k] <= r - i) {
				// i lies between l and r.
				// Z will exist previously.
				Z[i] = Z[k];
			} else {
				// Some part of Z is already included.
				// You have to start matching further.
				l = i;
				while (r < n && str[r - l] == str[r]) {
					r++;
				}
				Z[i] = r - l;
				r--;
			}
		}
	}
}

void searchString(string text, string pattern) {
	string str = pattern + "$" + text;
	int n = str.length();
	int lengthpat = pattern.length();
	int* Z = new int[n]();
	buildZ(Z, str);
	for (int i = 0; i < n; i++) {
		if (Z[i] == lengthpat) {
			cout << i - lengthpat - 1 << endl;
		}
	}
}

int main() {
	string str = "aadfghjklhjk";
	string pat = "hjk";
	searchString(str, pat);
	return 0;
}