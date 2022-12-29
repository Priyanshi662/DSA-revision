#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool optimize_solve(string s1,string s2)
        {
            // using queue data structure
            queue<char> q1,q2;
            for(int i=0;i<s1.size();i++)
            {
                q1.push(s1[i]);
                q2.push(s2[i]);
            }
            int k=s2.size();
            while(k--)
            {
                char x=q2.front();
                q2.pop();
                q2.push(x);
                if(q2==q1)
                    return true;
            }
            return false;
            // time complexity : O(N^2)
            // space complexity : O(N)
        }
        bool eff_solve(string s1,string s2) 
        {
            if(s1.size()!=s2.size())
                return false;
            string s3=s1+s1;
            int i=0;
            int j=s2.size()-1;
            while(j<s3.size())
            {
                string temp=s3.substr(i,j);
                // cout<<temp<<endl;
                if(temp==s2)
                    return true;
                i++;
                j++;
            }
            return false;
            // Time complexity : O(n)
            // Space complexity : O(n)
        }
        bool stl_solve(string s1,string s2)
        {
            if(s1.size()!=s2.size())
            {
                return false;
            }
            string s3=s1+s1;
            if(s3.find(s2)!=string::npos)
            {
                return true;
            }
            // Time complexity : O(n)
            // Space complexity : O(n)
        }
};
int main()
{
    string s1,s2;
    cout<<"Enter first string : ";
    cin>>s1;
    cout<<"Enter second string : ";
    cin>>s2;
    Solution ob;
    bool ans=ob.optimize_solve(s1,s2);
    if(ans)
    {
        cout<<"The two strings are rotations of each other. ";
    }
    else
    {
        cout<<"The two strings are not rotations of each other. ";
    }
    return 0;
}