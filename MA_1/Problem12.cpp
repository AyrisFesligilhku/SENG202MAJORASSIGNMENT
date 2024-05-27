#include <vector>
#include <iostream> // Include iostream for cout

using namespace std;

/* PROBLEM 12: DIVIDE AND CONQUER */

class Solution {
public:
    int solve(int current, int stepsLeft, int totalSteps, int maxStep, vector<vector<int>>& dp) {
        if (stepsLeft == 0)
            return 1;
        if (current > maxStep)
            return 0;
        if (dp[current][stepsLeft] != -1)
            return dp[current][stepsLeft];

        int takeStep = solve(current * 2, stepsLeft - 1, totalSteps, maxStep, dp);
        int skipStep = solve(current + 1, stepsLeft, totalSteps, maxStep, dp);

        return dp[current][stepsLeft] = takeStep + skipStep;
    }

    int numberSequence(int maxStep, int totalSteps) {
        vector<vector<int>> dp(maxStep + 1, vector<int>(totalSteps + 1, -1));
        return solve(1, totalSteps, totalSteps, maxStep, dp);
    }
};

int main() {
    Solution sol;
    int maxStep = 10;
    int totalSteps = 4;
    int result = sol.numberSequence(maxStep, totalSteps);
    cout << "Number of sequences: " << result << endl;
    return 0;
}
