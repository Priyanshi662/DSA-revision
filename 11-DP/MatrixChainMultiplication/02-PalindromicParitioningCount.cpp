#include <string>
#include <string.h>
using namespace std;

class Solution{
public:
    int dp[1001][1001];
    bool isPalindrome(string &str,int i,int j)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str,int i,int j,int minans)
    {
        if(i>=j)
        return dp[i][j]=0;
        
        // As no partition is required for a palindromic substring
        if(isPalindrome(str,i,j))
        return dp[i][j]=0;
         
        if(dp[i][j]!=-1)
        return dp[i][j];
        int left,right;
        for(int k=i;k<=j-1;k++)
        {
            if(dp[i][k]!=-1)
            left=dp[i][k];
            else
            left=solve(str,i,k,minans);
            if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
            else
            right=solve(str,k+1,j,minans);
            int temp=left+1+right;
            minans=min(minans,temp);
        }
        return dp[i][j]=minans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=str.size()-1;
        int minans=INT_MAX;
        return solve(str,i,j,minans);
    }
};