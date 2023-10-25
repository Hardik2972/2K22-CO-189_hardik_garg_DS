#include <iostream>
#include <stack>
using namespace std;
class queue
{
private:
    stack<int> input;
    stack<int> output;

public:
    void push(int val)
    {
        input.push(val);
    }
    int pop()
    {
        if (!output.empty())
        {
            int val = output.top();
            output.pop();
            return val;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int val = output.top();
            output.pop();
            return val;
        }
    }
    bool empty()
    {
        return input.empty() && output.empty();
    }
    int top()
    {
        if (input.empty() && output.empty())
        {
            return -1;
        }
        if (!output.empty())
        {
            return output.top();
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    q.push(4);
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }
}