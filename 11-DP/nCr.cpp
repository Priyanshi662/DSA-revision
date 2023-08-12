#include <string.h>
using namespace std;
int mod=1000000007;
int dp[1001][801];
int nCrUtil(int n,int r)
{
    if(r==0 || r==n)
        return dp[n][r]=1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    return dp[n][r]=(nCrUtil(n-1,r-1)+nCrUtil(n-1,r))%mod;
}
int nCr(int n, int r){
    memset(dp,-1,sizeof(dp));
    return nCrUtil(n,r);
}