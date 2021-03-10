/* Author :     Pranav Deshmukh
                PICT,Pune
   Purpose:     Create Graph and print it in BFS manner.
   Assumption:  vertices are numbered from 0 to n-1.
   Stay Focused!
*/

#include <iostream>
#include <queue>
using namespace std;

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

    cout << "BFS is :" << endl;
    printBFS(edges, n, 0 , visited);

    for (int i = 0; i < n; i++) {
        delete edges[i];
    }
    delete[] edges;
    delete[] visited;

    return 0;
}