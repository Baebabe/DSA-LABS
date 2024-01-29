#include<iostream>
#include<stack>
#include<string>
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
string infixToPrefix(string infix)
{
    stack<char> st;
    string res;
    infix='('+infix+')';
    int l=infix.size();
    for(int i=0;i<=l/2;i++){
        char temp=infix[i];
        infix[i]=infix[l-1-i];
        infix[l-1-i]=temp;
    }
    for (const char ch : infix)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            res += ch;
        }
        else if (ch == ')')
        {
            st.push(ch);
        }
        else if (ch == '(')
        {
            while (!st.empty() && st.top() != ')')
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
    l=res.size();
    for(int i=0;i<=l/2;i++){
        char temp=res[i];
        res[i]=res[l-1-i];
        res[l-1-i]=temp;
    }

    return res;
}

int main()
{
cout<<infixToPrefix("A*B-(C+D)+E");
return 0;
}