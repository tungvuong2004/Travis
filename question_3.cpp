#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printFirstNegativeInteger(vector<int>& arr, int k) {
    deque<int> negatives;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        
        if (!negatives.empty() && negatives.front() < i - k + 1) {
            negatives.pop_front();
        }

       
        if (arr[i] < 0) {
            negatives.push_back(i);
        }

       
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

