#include <iostream>
#include <algorithm>
using namespace std;

/* PROBLEM#5: SAME PROBLEM 4 WITH DYNAMIC PROGRAMMING */

class Pair {
public:
    int a;
    int b;
};

int maxChainLength(Pair arr[], int n) {
    sort(arr, arr + n, [](const Pair& p1, const Pair& p2) {
        return p1.b < p2.b;
        });

    int* maxChainLengths = new int[n];
    for (int i = 0; i < n; i++) {
        maxChainLengths[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].a > arr[j].b && maxChainLengths[i] < maxChainLengths[j] + 1) {
                maxChainLengths[i] = maxChainLengths[j] + 1;
            }
        }
    }

    int maxChain = *max_element(maxChainLengths, maxChainLengths + n);
    delete[] maxChainLengths;
    return maxChain;
}

int main() {
    Pair arr[] = { {5, 24}, {15, 25}, {27, 40}, {50, 60} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of maximum size chain is " << maxChainLength(arr, n) << endl;
    return 0;
}
