#include <iostream>
#include <stack>
using namespace std;

bool isbalancedparanthesis(string sentence)
{
    stack<char> st;

    for (const auto ch : sentence)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (!st.empty() &&
                 ((ch == ')' && st.top() == '(') ||
                  (ch == '}' && st.top() == '{') ||
                  (ch == ']' && st.top() == '[')))
        {
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    string sentence = "{[()]}";

    if (isbalancedparanthesis(sentence))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}
