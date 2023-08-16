#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// Brute Force:
int minCoins(vector<int> & coins,int amt,int n)
{
    if(n>=coins.size() || amt<=0)
    {
        if(amt==0)
            return 0;
        else
            return INT_MAX-1;
    }
    int res=-1;
    int notTake=minCoins(coins,amt,n+1);
    int take=INT_MAX-1;
    if(coins[n]<=amt)
    {
        take=1+minCoins(coins,amt-coins[n],n);
    }
    res=min(take,notTake);
    return res;
}
int coinChange(vector<int>& coins, int amount) {
    int res= minCoins(coins,amount,0);
    res=(res==INT_MAX-1)?-1:res;
    return res;
}
// Optimal :
// Memoization:
class Solution {
public:
    int dp[12+1][10001];
    int minCoins(vector<int> & coins,int amt,int n)
    {
        if(n>=coins.size() || amt<=0)
        {
            if(amt==0)
                return dp[n][amt]=0;
            else
                return dp[n][amt]= INT_MAX-1;
        }
        if(dp[n][amt]!=-1)
            return dp[n][amt];
        int res=-1;
        int notTake=minCoins(coins,amt,n+1);
        int take=INT_MAX-1;
        if(coins[n]<=amt)
        {
            take=1+minCoins(coins,amt-coins[n],n);
        }
        res=min(take,notTake);
        return dp[n][amt]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res= minCoins(coins,amount,0);
        res=(res==INT_MAX-1)?-1:res;
        return res;
    }
};
// Tabulation:
class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=n;i++)
        {
            //Flag for it is not processed for future
            dp[i]=INT_MAX;
            for(int c:coins)
            {
                if((i-c)<0)
                    break;
                if(dp[i-c]!=INT_MAX) 
                    dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        return (dp[n]==INT_MAX)? -1:dp[n];
    }
};