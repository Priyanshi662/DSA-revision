#include <iostream>
#include <string.h>
using namespace std;

int dp[1001][1001];

int longestRepeatingSubsequence(string a,string &res)
{
    int n=a.size();
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if((a[i-1]==a[j-1])&& i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            if(i==j)
            {
                if(dp[i][j]!=dp[i-1][j-1])
                {
                    res.push_back(a[i-1]);
                }
            }
        }
    }
    return dp[n][n];
}

int main()
{
    memset(dp,0,sizeof(dp));
    string a="AXXZXY";
    string res="";
    int len=longestRepeatingSubsequence(a,res);
    cout<<len<<endl;
    cout<<res<<endl;
    return 0;
}