#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4
using namespace std;

/* PROBLEM#6: BACKTRACKING */

void getAllPaths(int matrix[MAX][MAX], int n, int row, int col, vector<string>& paths, string currentPath) {
    if (row >= n || col >= n || row < 0 || col < 0 || matrix[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1) {
        paths.push_back(currentPath);
        return;
    }

    matrix[row][col] = 0;

    getAllPaths(matrix, n, row - 1, col, paths, currentPath + "U");
    getAllPaths(matrix, n, row, col + 1, paths, currentPath + "R");
    getAllPaths(matrix, n, row, col - 1, paths, currentPath + "L");
    getAllPaths(matrix, n, row + 1, col, paths, currentPath + "D");

    matrix[row][col] = 1;
}

vector<string> findPaths(int matrix[MAX][MAX], int n) {
    vector<string> paths;
    getAllPaths(matrix, n, 0, 0, paths, "");
    return paths;
}

int main() {
    int matrix[MAX][MAX] = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    int n = sizeof(matrix) / sizeof(matrix[0]);
    vector<string> paths = findPaths(matrix, n);

    if (paths.empty()) {
        cout << "-1";
    }
    else {
        sort(paths.begin(), paths.end());
        for (const auto& path : paths)
            cout << path << " ";
    }
    return 0;
}
