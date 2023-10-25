#include <iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int capacity)
    {
        size = capacity;
        arr = new int[size];
        front = rear = -1;
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    int pop()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        int val = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return val;
    }
    int peek()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        return front == -1 && rear == -1;
    }
};
int main()
{
    Queue q(5);
    cout << q.pop() << endl;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "peek element is " << q.peek() << endl;
    while (!q.empty())
    {
        cout << q.peek() << " ";
        q.pop();
    }
    cout << endl
         << "is empty " << q.empty() << endl;
}