#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// PROBLEM#2: GREEDY ALGORITHM

struct Job {
    int id;
    int deadline;
    int profit;
};

class Solution
{
public:
    static bool compareProfit(const Job& job1, const Job& job2) {
        return job1.profit > job2.profit;
    }

    vector<int> jobScheduling(Job arr[], int n) {
        int maxDeadline = arr[0].deadline;
        for (int i = 1; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }
        vector<int> schedule(maxDeadline + 1, -1);
        sort(arr, arr + n, compareProfit);

        int jobCount = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].deadline; j > 0; j--) {
                if (schedule[j] == -1) {
                    schedule[j] = arr[i].id;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return { jobCount, totalProfit };
    }
};

int main() {
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    Solution solution;
    vector<int> result = solution.jobScheduling(jobs, n);
    cout << "Number of jobs scheduled: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    return 0;
}
