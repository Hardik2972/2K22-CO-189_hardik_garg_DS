#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
vector<int> NGE_LeftTORight(vector<int> arr, vector<int> query)
{
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] < arr[i])
        {
            mp[arr[st.top()]] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        mp[arr[st.top()]] = -1;
        st.pop();
    }
    for (int i = 0; i < query.size(); i++)
    {
        ans.push_back(mp[query[i]]);
    }
    return ans;
}
vector<int> NGE_RightToLeft(vector<int> arr, vector<int> query)
{
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] < arr[i])
        {
            mp[arr[st.top()]] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        mp[arr[st.top()]] = -1;
        st.pop();
    }
    for (int i = 0; i < query.size(); i++)
    {
        ans.push_back(mp[query[i]]);
    }
    return ans;
}
vector<int> NSE_LeftTORight(vector<int> arr, vector<int> query)
{
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            mp[arr[st.top()]] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        mp[arr[st.top()]] = -1;
        st.pop();
    }
    for (int i = 0; i < query.size(); i++)
    {
        ans.push_back(mp[query[i]]);
    }
    return ans;
}
vector<int> NSE_RightToLeft(vector<int> arr, vector<int> query)
{
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            mp[arr[st.top()]] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        mp[arr[st.top()]] = -1;
        st.pop();
    }
    for (int i = 0; i < query.size(); i++)
    {
        ans.push_back(mp[query[i]]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cout << "enter no. of query " << endl;
    cin >> m;
    vector<int> query(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i];
    }
    vector<int> result1 = NSE_RightToLeft(arr, query);
    cout << "NSE_RightToLeft ";
    for (auto elem : result1)
    {
        cout << elem << " ";
    }
    cout << endl;
    
    vector<int> result2 = NSE_LeftTORight(arr, query);
    cout << "NSE_LeftTORight ";
    for (auto elem : result2)
    {
        cout << elem << " ";
    }
    cout << endl;
    vector<int> result3 = NGE_RightToLeft(arr, query);
    cout << "NGE_RightToLeft ";
    for (auto elem : result3)
    {
        cout << elem << " ";
    }
    cout << endl;
    vector<int> result4 = NGE_LeftTORight(arr, query);
    cout << "NGE_LeftTORight ";
    for (auto elem : result4)
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}