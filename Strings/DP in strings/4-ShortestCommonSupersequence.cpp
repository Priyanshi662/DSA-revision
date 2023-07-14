#include <iostream>
#include <string.h>
using namespace std;

int dp[1001][1001];
int findlcs(string x,string y,int n,int m)
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

int findShortestSupersequence(string x,string y)
{
    int n=x.size();
    int m=y.size();
// length of shortest supersequence is n+m - len(LCS)
// cuz adding both strings there will be common subsequence added twice
    int lenlcs=findlcs(x,y,n,m);
    return (n+m - lenlcs);
}