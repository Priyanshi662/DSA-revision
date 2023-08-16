#include <algorithm>
#include <string.h>
using namespace std;

int dp[101][101];
int mcmcost(int n ,int arr[],int i,int j,int mincost)
{
    if(i>=j)
        return dp[i][j]=0;
    int k=i;
    int tempcost;
    if(dp[i][j]!=-1)
        return dp[i][j];
    for(;k<j;k++)
    {
        tempcost= mcmcost(n,arr,i,k,mincost)+
        mcmcost(n,arr,k+1,j,mincost)+
        arr[i-1]*arr[k]*arr[j];
        mincost=min(tempcost,mincost);
    }
    return dp[i][j]=mincost;
}
int matrixMultiplication(int N, int arr[])
{
    int mincost=INT_MAX;
    memset(dp,-1,sizeof(dp));
    return mcmcost(N,arr,1,N-1,mincost);
}