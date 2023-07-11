#include <iostream>
#include <string>
#include <stack>
using namespace std;

string revWords(string s)
{
    stack<string> st;
    string temp="";
    s+=" ";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            temp+=" ";
            st.push(temp);
            temp="";
        }
        else
            temp+=s[i];
    }
    temp="";
    while(!st.empty())
    {
        string t=st.top();
        st.pop();
        temp+=t;
    }
    return temp;
}
int main()
{
    string s="Priyanshi is a very beautiful girl";
    string res=revWords(s);
    cout<<res<<endl;
    return 0;
}