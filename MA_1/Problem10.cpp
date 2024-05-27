#include <iostream> // Include iostream for cout

using namespace std;

/* PROBLEM 10: DIVIDE AND CONQUER */

int findKthElement(int arr1[], int arr2[], int m, int n, int k) {
    int count = 0, i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == k)
                return arr1[i];
            i++;
        }
        else {
            count++;
            if (count == k)
                return arr2[j];
            j++;
        }
    }

    while (i < m && count < k) {
        count++;
        if (count == k)
            return arr1[i];
        i++;
    }

    while (j < n && count < k) {
        count++;
        if (count == k)
            return arr2[j];
        j++;
    }

    // If k is out of bounds
    return -1; // Indicate that k is out of bounds
}

int main() {
    int A[5] = { 2, 3, 6, 7, 9 };
    int B[4] = { 1, 4, 8, 10 };
    int k = 5;
    cout << "The " << k << "th smallest element is: " << findKthElement(A, B, 5, 4, k) << endl;
    return 0;
}
