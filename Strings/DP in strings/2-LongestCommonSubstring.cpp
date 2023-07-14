#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int longestCommonSubstring1(string x,string y,int m,int n,int &maxcount,bool cont)
{ 
    if(m==0 || n==0)
        return 0;
    if(cont)
    {
        if(x[m-1]==y[n-1])
        {
            maxcount=max(maxcount,1+longestCommonSubstring1(x,y,m-1,n-1,maxcount,cont));
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(x[m-1]==y[n-1])
        {
            maxcount=max(maxcount,1+longestCommonSubstring1(x,y,m-1,n-1,maxcount,cont));
        }
            maxcount=max({maxcount,longestCommonSubstring1(x,y,m,n-1,maxcount,!cont),longestCommonSubstring1(x,y,m-1,n,maxcount,!cont)});
    }
    return maxcount;
}
// top down approach:
int lcsubstring2(string x,string y,int m,int n,int &maxcount)
{
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                if(maxcount<dp[i][j])
                    maxcount=dp[i][j];
            }
            // else the dp[i][j] remains 0
        }
    }
    return maxcount;
}
int main()
{
    memset(dp,0,sizeof(dp));
    string a="ABCEDSFG";
    string b="EDSFABCE";
    int m=a.size();
    int n=b.size();
    int maxcount=INT_MIN;
    cout<<lcsubstring2(a,b,m,n,maxcount);
    return 0;
}