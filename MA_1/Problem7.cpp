#include <iostream>
#include <vector>
using namespace std;

/* PROBLEM#7: BACKTRACKING */

class Solution {
public:
    bool isSafe(int node, bool graph[101][101], vector<int>& color, int n, int col) {
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[node][neighbor] && color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, bool graph[101][101], vector<int>& color, int m, int n) {
        if (node == n) {
            return true;
        }

        for (int c = 1; c <= m; c++) {
            if (isSafe(node, graph, color, n, c)) {
                color[node] = c;
                if (solve(node + 1, graph, color, m, n)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        return solve(0, graph, color, m, n);
    }
};

int main() {
    int N = 3; // Number of nodes
    int M = 2; // Number of colors
    int E = 3; // Number of edges
    pair<int, int> edges[] = { {0, 1}, {1, 2}, {0, 2} };

    bool graph[101][101] = { false };
    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    Solution solution;
    cout << (solution.graphColoring(graph, M, N) ? "1" : "0") << endl;

    return 0;
}
