#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printNGE(vector<int>& arr) {
    stack<int> s;
    vector<int> nge(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    
    printNGE(arr);

    return 0;
}

