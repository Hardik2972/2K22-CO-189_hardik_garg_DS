#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize the top of the stack
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push " << value << std::endl;
        } else {
            arr[++top] = value;
            std::cout << value << " pushed onto the stack." << std::endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        } else {
            std::cout << arr[top] << " popped from the stack." << std::endl;
            top--;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a default value
        } else {
            return arr[top];
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.push(4);

    return 0;
}
