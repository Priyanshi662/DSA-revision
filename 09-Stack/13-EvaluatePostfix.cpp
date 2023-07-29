#include <stack>
#include <string>
using namespace std;

int eval(int a,int b,char op)
{
    int res;
    if(op=='*')
        res=a*b;
    else if(op=='+')
        res=a+b;
    else if(op=='-')
        res=a-b;
    else if(op=='/')
        res=a/b;
    return res;
}
int evaluatePostfix(string s)
{
    stack<int> st;
    // st stores operands
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else
        {
            int b=st.top();st.pop();
            int a=st.top();st.pop();
            int res=eval(a,b,s[i]);
            st.push(res);
            ans=res;
        }
    }
    return ans;
}