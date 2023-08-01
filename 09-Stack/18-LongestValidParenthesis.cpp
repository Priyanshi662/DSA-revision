#include <stack>
#include <string>
using namespace std;
class Solution {
public:
// using stack -> O(n) and O(n)
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] =='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxi=max(maxi,i-st.top());
                }
            }
        }
        return maxi;
    }
// using two iterations :O(n)
    int longestvalid(string s)
    {
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            else if(close>open)
            {
                close=0;
                open=0;
            }
        }
        open=0,close=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            else if(open>close)
            {
                close=0;
                open=0;
            }
        }
        return ans;
    }
};