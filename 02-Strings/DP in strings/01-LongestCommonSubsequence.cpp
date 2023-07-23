#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// recursive ->brute force
int findLen1(string x, string y,int n,int m)
{
    // empty strings have lcs=0
    if(n==0 || m==0)
        return 0;
    
    if(x[n-1]==y[m-1])
    {
        return 1+findLen1(x,y,n-1,m-1);
    }
    else
    {
        return max(findLen1(x,y,n,m-1),findLen1(x,y,n-1,m));
    }
}

// memoization->DP (optimal) ->TOPDOWN DP

int dp[1001][1001];
int findlen2(string x,string y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(x[n-1]==y[n-1])
        return dp[n][m]=1+findlen2(x,y,n-1,m-1);
    else
    {
        int a=findlen2(x,y,n,m-1);
        int b=findlen2(x,y,n-1,m);
        dp[n][m]=max(a,b);
        return dp[n][m];
    }
}

// Bottom -up DP
int findlen3(string x,string y,int n,int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
        }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i]==y[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string x="ABCDGH";
    string y="ABEDFHR";
    int n=x.size();
    int m=y.size();
    memset(dp,-1,sizeof(dp));
    cout<<findlen3(x,y,n,m)<<endl;
    return 0;
}