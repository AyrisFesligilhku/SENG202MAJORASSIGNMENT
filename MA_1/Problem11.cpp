#include <algorithm>
#include <numeric>
#include <iostream> // Include iostream for cout

using namespace std;

/* PROBLEM 11: DIVIDE AND CONQUER */

class Solution {
public:
    bool isFeasible(int books[], int numBooks, int numStudents, int maxPages) {
        int currentPageSum = 0;
        int studentCount = 1;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i] > maxPages) {
                return false;
            }
            if (currentPageSum + books[i] > maxPages) {
                studentCount++;
                currentPageSum = books[i];
                if (studentCount > numStudents) {
                    return false;
                }
            }
            else {
                currentPageSum += books[i];
            }
        }
        return true;
    }

    int findMinPages(int books[], int numBooks, int numStudents) {
        if (numBooks < numStudents) {
            return -1;
        }

        int totalPages = accumulate(books, books + numBooks, 0);
        int low = 1, high = totalPages, mid;
        int result = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isFeasible(books, numBooks, numStudents, mid)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int books[] = { 12, 34, 67, 90 };
    int numBooks = sizeof(books) / sizeof(books[0]);
    int numStudents = 2;
    cout << "Minimum number of pages: " << solution.findMinPages(books, numBooks, numStudents) << endl;
    return 0;
}
