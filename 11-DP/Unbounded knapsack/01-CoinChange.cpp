#include <iostream>
#include <string.h>
using namespace std;

int dp[101][1001];
int NumberOfCoinsNeeded(int value[],int sum,int n)
{
    if(n>=0 && sum==0)
        return dp[n][sum]=1;
    if(n==0)
        return dp[n][sum]=0;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    int nottake=NumberOfCoinsNeeded(value,sum,n-1);
    int take=0;
    if(value[n-1]<=sum)
        take=1+NumberOfCoinsNeeded(value,sum-value[n-1],n-1);
    return dp[n][sum]=max(take,nottake);
}
