#include<iostream>
using namespace std;
#include <stack>
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}
bool operand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

string infixToPostfix(string exp)
{
    stack<char> st;
    int n = exp.length();
    string postfix = "";
    for (int i = 0; i < n; i++)
    {
        char ch = exp[i];

        if (operand(ch))
        {
            postfix.push_back(ch);
        }
        else
        {
            if (st.empty() || st.top() == '(' || ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence(st.top()) >= precedence(ch))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while (!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
int main()
{
    
        string exp;
        cin >> exp;
        cout << infixToPostfix(exp) << endl;

        return 0;
}