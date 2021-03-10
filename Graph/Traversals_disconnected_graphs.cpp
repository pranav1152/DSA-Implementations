/* Author : 	Pranav Deshmukh
            	PICT,Pune
   Purpose: 	BFS and DFS for disconnected graphs.
   Assumption: 	vertices are numbered from 0 to n-1.
   Stay Focused!
*/

#include <iostream>
#include <queue>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited) {
	cout << sv << " ";
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

void printBFS(int** edges, int n, int sv, bool* visited) {
	queue<int> pending_vertices;
	pending_vertices.push(sv);
	visited[sv] = true;
	while (pending_vertices.size() != 0) {
		int front = pending_vertices.front();
		pending_vertices.pop();
		cout << front << " ";
		for (int i = 0; i < n; i++) {
			if (i == front) {
				continue;
			}
			if (edges[front][i] == 1) {
				if (visited[i]) {
					continue;
				}
				pending_vertices.push(i);
				visited[i] = true;
			}
		}
	}
}

void DFS(int** edges, int n) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			printDFS(edges, n, i, visited);
	}
	delete[] visited;
	cout << endl;
}

void BFS(int** edges, int n) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			printBFS(edges, n, i, visited);
	}
	delete[] visited;
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
	cout << "DFS" << endl;
	DFS(edges, n);
	cout << "BFS" << endl;
	BFS(edges, n);

	for (int i = 0; i < n; i++) {
		delete edges[i];
	}
	delete[] edges;

	return 0;
}
