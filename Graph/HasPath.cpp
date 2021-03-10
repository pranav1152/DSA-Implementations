/* Author : 	Pranav Deshmukh
            	PICT,Pune
   Purpose: 	If there is path between starting vertex and ending vertex.
   Assumption: 	vertices are numbered from 0 to n-1.
   Stay Focused!
*/

#include <iostream>
#include <queue>
using namespace std;

bool hasPathDFS(int** edges, int n, int sv, int ev, bool* visited) {
	if (sv == ev)
		return true;
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (edges[sv][i] == 1) {
			if (visited[i]) {
				continue;
			}
			if (hasPathDFS(edges, n, i, ev, visited))
				return true;
		}
	}
	return false;
}

bool hasPathBFS(int** edges, int n, int sv, int ev, bool* visited) {
	queue<int> pending_vertices;
	pending_vertices.push(sv);
	visited[sv] = true;
	while (pending_vertices.size() != 0) {
		int front = pending_vertices.front();
		pending_vertices.pop();
		if (front == ev)
			return true;
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
	return false;
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
	int sv, ev;
	cout << "Enter starting vertex:" << endl;
	cin >> sv;
	cout << "Enter ending vertex:" << endl;
	cin >> ev;
	if (hasPathDFS(edges, n, sv, ev, visited))
		cout << "Path exists : DFS" << endl;
	else
		cout << "Path doesn't exists : DFS" << endl;
	if (hasPathBFS(edges, n, sv, ev, visited))
		cout << "Path exists : BFS" << endl;
	else
		cout << "Path doesn't exists : BFS" << endl;

	for (int i = 0; i < n; i++) {
		delete edges[i];
	}
	delete[] edges;

	return 0;
}
