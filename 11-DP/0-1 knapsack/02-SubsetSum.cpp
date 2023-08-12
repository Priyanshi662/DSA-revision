#include <iostream>
#include <vector>
using namespace std;

bool dp[1001][1001];
bool subsetExists(vector<int> &nums,int target,int n)
{
    if(target==0)
        return dp[n][target]=true;
    if(n==0)
        return dp[n][target]=false;

    if(dp[n][target])
        return dp[n][target];

    if(nums[n-1] <= target)
    {
        bool x=subsetExists(nums,target-nums[n-1],n-1);
        bool y=subsetExists(nums,target,n-1);
        return dp[n][target]=x||y;
    }
    else
        return dp[n][target]=subsetExists(nums,target,n-1);
}
bool subsetExists2(vector<int> &nums,int target,int n)
{
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<target+1;j++)
        {
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
            else if(nums[i-1]<= j)
            {
                dp[i][j]=dp[i-1][j] || (dp[i-1][j-nums[i-1]]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}
// we see that only current row and previous row is needed for the computation of the sum
// thus we can reduce the space by storing the dp in a linear array
bool FindSumExists(vector<int> &nums,int target,int n)
{
    vector<bool> prev(target+1,false);
    prev[0]=true;
    vector<bool> curr(target+1,false);
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<target+1;j++)
        {
            if(nums[i-1]<=j)
                curr[j]=prev[j-1]||prev[j-nums[i-1]];
            else
                curr[j]=prev[i-1];
        }
        prev=curr;
    }
    return curr[target];
}