/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;

	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;

	//Following line will give error Key not found
	//cout<<ourmap.at("ghi")<<endl;

	cout << "size : " << ourmap.size() << endl;
	cout << ourmap["ghi"] << endl;
	//This will insert key and initialize it with default null.
	cout << "size : " << ourmap.size() << endl;

	// Check Presence
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}
	return 0;
}
