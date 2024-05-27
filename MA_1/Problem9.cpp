#include <vector>
#include <string>
#include <iostream> // Include iostream for cout

using namespace std;

/* PROBLEM 9: BACKTRACKING */

class Solution {
public:
    bool dfs(int row, int col, int ind, vector<vector<char>>& board, string& word, vector<vector<int>>& vis) {
        if (ind == word.length()) { // Changed to use length() for clarity
            return true;
        }
        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;

        static const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
        static const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

        for (int i = 0; i < 8; ++i) { // Added prefix increment for style
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[ind]) {
                if (dfs(nrow, ncol, ind + 1, board, word, vis))
                    return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dict) {
        vector<string> ans;
        int n = board.size(), m = board[0].size();

        for (const auto& word : dict) { // Use auto for type deduction
            bool found = false;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == word[0] && !vis[i][j] && dfs(i, j, 1, board, const_cast<string&>(word), vis)) { // Use const_cast to remove constness
                        ans.push_back(word);
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'C', 'A', 'P'},
        {'A', 'N', 'D'},
        {'T', 'I', 'E'}
    };
    vector<string> dictionary = { "CAT" };
    vector<string> result = sol.wordBoggle(board, dictionary);
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}
