#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
float evaluate(string exp){
    stack<float> st;
    for(const char ch:exp){
        if(ch>='0' && ch <='9'){
            st.push(ch-'0');
        }
        else{
            float b= st.top();
            st.pop();

            float a=st.top();
            st.pop();
            switch (ch)
            {
            case '^':
                st.push(pow(a,b));
                break;
            case '/':
                st.push(a/b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            default:
                break;
            }
             
        }
    }
    return st.top();
}
int main()
{
 cout << evaluate("123*+84/+1+")<<endl;
return 0;
}