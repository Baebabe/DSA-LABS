#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string res;
    for (const char ch : infix)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            res += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    cout << infixToPostfix("A*B-(C+D)+E") << endl;
    return 0;
}
