#include <vector>
#include <string>
#include <iostream> // Include iostream for cout

using namespace std;

/* PROBLEM 8: BACKTRACKING */

bool isValidSegment(const string& segment) {
    if (segment.empty() || segment.size() > 3 || (segment[0] == '0' && segment.size() > 1))
        return false;
    int value = stoi(segment);
    return value >= 0 && value <= 255;
}

void generateIPAddresses(vector<string>& result, const string& givenString, int index, int count, string ipAddress) {
    if (index == static_cast<int>(givenString.size()) && count == 4) {
        ipAddress.pop_back(); // Remove the last dot
        result.push_back(ipAddress);
        return;
    }

    if (index == static_cast<int>(givenString.size()) || count == 4)
        return;

    string segment1 = givenString.substr(index, 1);
    if (isValidSegment(segment1)) {
        generateIPAddresses(result, givenString, index + 1, count + 1, ipAddress + segment1 + '.');
    }

    if (index + 1 < static_cast<int>(givenString.size())) {
        string segment2 = givenString.substr(index, 2);
        if (isValidSegment(segment2)) {
            generateIPAddresses(result, givenString, index + 2, count + 1, ipAddress + segment2 + '.');
        }
    }

    if (index + 2 < static_cast<int>(givenString.size())) {
        string segment3 = givenString.substr(index, 3);
        if (isValidSegment(segment3)) {
            generateIPAddresses(result, givenString, index + 3, count + 1, ipAddress + segment3 + '.');
        }
    }
}

int main() {
    string givenString = "11211";
    vector<string> result;
    generateIPAddresses(result, givenString, 0, 0, "");
    if (result.empty()) {
        cout << "-1\n";
    }
    else {
        for (const string& ip : result) {
            cout << ip << "\n";
        }
    }
    return 0;
}
