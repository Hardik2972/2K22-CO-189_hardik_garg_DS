#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
        if (stack.empty()) {
            // If the stack is empty, set x as both the element and the minimum.
            stack.push(x);
            minElement = x;
        } else {
            if (x < minElement) {
                // If x is smaller than the current minimum, push 2*x - minElement onto the stack
                // and update minElement to x.
                stack.push(2 * x - minElement);
                minElement = x;
            } else {
                // If x is greater than or equal to the current minimum, simply push x onto the stack.
                stack.push(x);
            }
        }
    }

    void pop() {
        if (stack.empty()) {
            // Handle the case of an empty stack.
            return;
        }

        int top = stack.top();
        stack.pop();

        if (top < minElement) {
            // If the popped element is less than the current minimum, update minElement.
            minElement = 2 * minElement - top;
        }
    }

    int top() {
        if (stack.empty()) {
            // Handle the case of an empty stack.
            return -1; // You can choose any appropriate value here.
        }

        int top = stack.top();
        if (top < minElement) {
            // If the top element is less than the current minimum, the real top element is the minimum.
            return minElement;
        } else {
            // Otherwise, the real top element is top.
            return top;
        }
    }

    int getMin() {
        return minElement;
    }

private:
    stack<int> stack;
    int minElement;
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(2);
    minStack.push(4);
    minStack.push(1);

    cout << "Minimum element: " << minStack.getMin() << endl;

    minStack.pop();

    cout << "Minimum element after pop: " << minStack.getMin() << endl;

    return 0;
}
