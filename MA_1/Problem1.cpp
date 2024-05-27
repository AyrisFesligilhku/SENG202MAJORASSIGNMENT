#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// PROBLEM#1: GREEDY ALGORITHM

class Solution {
public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({ end[i], start[i] });
        }
        sort(meetings.begin(), meetings.end());
        int last_end_time = meetings[0].first;
        int meeting_count = 1;
        for (int i = 1; i < n; i++) {
            if (meetings[i].second > last_end_time) {
                last_end_time = meetings[i].first;
                meeting_count++;
            }
        }
        return meeting_count;
    }
};

int main() {
    int n = 6;
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    Solution solution;
    int max_meetings = solution.maxMeetings(start, end, n);
    cout << "Maximum number of meetings: " << max_meetings << endl;

    return 0;
}
