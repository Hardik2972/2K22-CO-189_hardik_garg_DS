#include <iostream>
using namespace std;
int main()
{

    string str;
    cin >> str;
    int size = str.length();
    int i = 0, j = size - 1;
    bool flag = 0;
    while (i <= j)
    {
        if (str[i] != str[j])
        {
            cout << "string is not palindrome" << endl;
            flag = 1;
            break;
        }
        i++;
        j--;
    }

    if (flag == 0)
    {
        cout << "string is palindrome" << endl;
    }

    return 0;
}