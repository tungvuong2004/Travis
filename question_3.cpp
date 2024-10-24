#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printFirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> negatives;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove elements that are out of this window
        if (!negatives.empty() && negatives.front() < i - k + 1) {
            negatives.pop_front();
        }

        // If the current element is negative, add its index to the deque
        if (arr[i] < 0) {
            negatives.push_back(i);
        }

        // Print the first negative integer of the current window
        if (i >= k - 1) {
            if (!negatives.empty()) {
                cout << arr[negatives.front()] << " ";
            } else {
                cout << "0 ";
            }
        }
    }
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    printFirstNegativeInteger(arr, k);

    return 0;
}

