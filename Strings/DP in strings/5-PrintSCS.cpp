#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution {
public:
int dp[1001][1001];
void findlcs(string x,string y,int n,int m)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
        }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
    string findSCS(string s1,string s2)
    {
        string res="";
        int i=s1.size();
        int j=s2.size();
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                res.push_back(s1[i-1]);
                i--;
            }
            else
            {
                res.push_back(s2[j-1]);
                j--;
            }
        }
        while(i>0)
        {
            res.push_back(s1[i-1]);
            i--;
        }
        while(j>0)
        {
            res.push_back(s2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        memset(dp,0,sizeof(dp));
        findlcs(str1,str2,n,m);
        return findSCS(str1,str2);
    }
};