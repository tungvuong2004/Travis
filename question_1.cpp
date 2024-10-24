#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& s, int item) {
    // Base case: If stack is empty, insert the item at the bottom
    if (s.empty()) {
        s.push(item);
        return;
    }

    // Otherwise, pop the top element and recur
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, item);

    // Push the top element back after the recursive call
    s.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& s) {
    // Base case: If stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recur for the rest of the stack
    reverseStack(s);

    // Insert the popped element at the bottom
    insertAtBottom(s, topElement);
}

// Helper function to print the elements of the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Push elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original Stack: ";
    printStack(s);

    // Reverse the stack
    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}

