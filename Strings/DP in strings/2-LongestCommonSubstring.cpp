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
int main()
{
    memset(dp,0,sizeof(dp));
    string a="ABCEDSFG";
    string b="EDSFABCE";
    int m=a.size();
    int n=b.size();
    int maxcount=INT_MIN;
    cout<<longestCommonSubstring1(a,b,m,n,maxcount,false);
    return 0;
}