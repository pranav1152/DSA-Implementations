/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

#include <bits/stdc++.h>
using namespace std;

void print(int** solutions, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << solutions[i][j] << " ";
		}
	}
	cout << endl;
}

void rathelper(int maze[][20], int** solutions, int n, int x, int y) {

	if (x == n - 1 && y == n - 1) {
		solutions[x][y] = 1;
		print(solutions, n);
		solutions[x][y] = 0;
		return;
	}

	if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || solutions[x][y] == 1 || maze[x][y] == 0)
		return;
	solutions[x][y] = 1;
	rathelper(maze, solutions, n, x - 1, y);
	rathelper(maze, solutions, n, x + 1, y);
	rathelper(maze, solutions, n, x, y + 1);
	rathelper(maze, solutions, n, x, y - 1);
	solutions[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n) {

	int** solutions = new int*[n];
	for (int i = 0; i < n; i++) {
		solutions[i] = new int[n];
	}

	rathelper(maze, solutions, n, 0, 0);
}
