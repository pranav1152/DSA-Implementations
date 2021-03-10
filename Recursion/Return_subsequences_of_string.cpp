/* Author : Pranav Deshmukh
            PICT,Pune

   Purpose: Return Subsequences of String
   Stay Focused!
*/

#include<bits/stdc++.h>
using namespace std;

//Substrings are consecutive parts of a string,while subsequences need not be.

int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}
int main() {
	string input;
	cout << "Enter String:" << endl;
	cin >> input;
	cout << "Subsequences are:" << endl;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
	return 0;
}