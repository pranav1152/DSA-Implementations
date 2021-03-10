/* Author : 	Pranav Deshmukh
            	PICT,Pune
   Purpose: 	Create Graph and print it in DFS manner.
   Assumption: 	vertices are numbered from 0 to n-1.
   Stay Focused!
*/

#include <iostream>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited) {
	cout << sv << endl;
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (edges[sv][i] == 1) {
			if (visited[i]) {
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

int main() {
	int n, e;
	cout << "Number of vertices:" << endl;
	cin >> n;
	cout << "Number of edges:" << endl;
	cin >> e;
	cout << "Enter first and second vertices of edges respectively:" << endl;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	cout << "DFS is :" << endl;
	printDFS(edges, n, 0, visited);

	delete visited;
	for (int i = 0; i < n; i++) {
		delete edges[i];
	}
	delete[] edges;

	return 0;
}