/* Author : Pranav Deshmukh
            PICT,Pune

   Purpose: How vectors works internally
   Stay Focused!
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;

	for (int i = 0; i < 100; i++) {
		// Capacity is size of underlying array
		cout << "Capacity of vector:" << v.capacity() << endl;
		cout << "Size of vector:" << v.size() << endl;
		v.push_back(i + 1);
	}
	return 0;
}