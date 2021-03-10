/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Create,Insert,Delete, Search in Trie.
   Stay Focused!
*/

#include<iostream>
using namespace std;

// Single Trie Node
class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isterminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isterminal = false;
	}
};


// Create,Insert,Delete, Search in Trie
class Trie {
	TrieNode* root;

public:

	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode* root, string word) {
		// Base Case
		if (word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode* child;
		if (root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		insertWord(child, word.substr(1));
	}

	// For user to simple insert
	void insertWord(string word) {
		insertWord(root, word);
	}

	bool search(TrieNode* root, string word) {
		// Base Case
		if (word.size() == 0) {
			if (root -> isTerminal == true)
				return true;
			return false;
		}

		// Small Calculation
		int index = word[0] - 'a';
		if (root -> children[index] != NULL) {
			TrieNode* child = root -> children[index];
			return search(child, word.substr(1));
		}
		else {
			return false;
		}
	}

	//For user to simple search
	bool search(string word) {
		search(root, word);
	}

	void removeWord(TrieNode* root, string word) {
		// Base Case
		if (word.size() == 0) {
			root -> isTerminal = false;
			return;
		}

		// Small calculation
		TrieNode* child;
		int index = word[0] - 'a';
		if (root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			// Word not found
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child Node if it is useless
		if (child -> isTerminal == false) {
			for (int i = 0; i < 26; i++) {
				if (child -> children[i] != NULL) {
					return;
				}
			}
			delete child;
			root -> children[index] = NULL;
		}
	}

	//For user to simple delete
	void removeWord(string word) {
		removeWord(root, word);
	}
};

int main() {
	Trie t;
	int n;
	cout << "Enter total number of words" << endl;
	cin >> n;
	cout << "Enter Words" << endl;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.insertWord(s);
	}
	int exit = 1;
	while (exit) {
		cout << "1.Insert Word" << endl;
		cout << "2.Search Word" << endl;
		cout << "3.Delete Word" << endl;
		cout << "4.Exit" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter Word" << endl;
			string s;
			cin >> s;
			t.insertWord(s);
		}
		else if (choice == 2) {
			cout << "Enter Word" << endl;
			string s;
			cin >> s;
			cout << t.search(s) << endl;
		}
		else if (choice == 3) {
			cout << "Enter Word" << endl;
			string s;
			cin >> s;
			removeWord(s);
		}
		else
			exit = 0;
	}
	return 0;
}
