#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// recursive approach
int findMaxProfit(int wt[],int val[],int n,int maxwt)
{
    if(n==0 || maxwt==0)
        return 0;
    int x=INT_MIN,y;
    if(wt[n-1] <= maxwt)
        x=val[n-1]+findMaxProfit(wt,val,n-1,maxwt-wt[n-1]);
    y=findMaxProfit(wt,val,n-1,maxwt);
    return max(x,y);
}
//Bottom up approach
int dp[1001][1001];
int findMaxProfit2(int wt[],int val[],int n,int maxwt)
{
    if(n==0 || maxwt==0)
        return dp[n][maxwt]=0;
    if(dp[n-1][maxwt!=-1])
        return dp[n-1][maxwt];
    int x=INT_MIN;
    int y;
    if(wt[n-1] <= maxwt)
        x=val[n-1]+findMaxProfit2(wt,val,n-1,maxwt-wt[n-1]);
    y=findMaxProfit2(wt,val,n-1,maxwt);
    return max(x,y);
}
// top down approach
int findMaxProfit3(int wt[],int val[],int n,int maxwt)
{
    vector<vector<int>> dp(n+1,vector<int>(maxwt+1,-1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<maxwt+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            int curr_ele=i-1;
            int curr_max_wt=j;
            if(wt[curr_ele]<=curr_max_wt)
            {
                int include=dp[curr_ele][j-wt[curr_ele]]+val[curr_ele];
                int exclude=dp[curr_ele][j];
                dp[i][j]=max(include,exclude);
            }
            else
            {
                dp[i][j]=dp[curr_ele][curr_max_wt];
            }
        }
    }
    return dp[n][maxwt];
}
int main()
{
    int wt[]={2,3,5,6,7};
    int val[]={3,4,5,2,1};
    int maxwt=16;
    int n=5;
    memset(dp,-1,sizeof(dp));
    cout<<findMaxProfit(wt,val,n,maxwt);
    return 0;
}