#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& s, int item) {
    if (s.empty()) {
        s.push(item);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, item);

    s.push(topElement);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, topElement);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}


