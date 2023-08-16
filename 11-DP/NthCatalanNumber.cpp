#include <iostream>

// Brute Force using recursive equation:
// C0=1 and Cn+1=addition(Ci * Cn-i)i=0 to n
int findCatalan(int n)
{
    if(n==0)
        return 1;
    int res=1;
    for(int i=0;i<n;i++)
    {
        res+=(findCatalan(i)*findCatalan(n-i));
    }
    return res;
}
// using DP
int dp[10001];
int findCatalan(int n)
{
    if(n==0)
        return dp[n]=1;
    int res=1;
    if(dp[n]!=-1)
        return dp[n];
    for(int i=0;i<n;i++)
    {
        res+=(findCatalan(i)*findCatalan(n-i));
    }
    return dp[n]=res;
}


// Optimal using formula
int nCr(int n,int k)
{
    int res=1;
    if (k > n - k)
        k = n - k;

// Calculate value of [n*(n-1)*---*(n-k+1)] /
// [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i) 
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
int findCatalan(int n) 
{
    // 2n!/(n!(n+1)!)
    // -> 2nCn /(n+1)
    // find 2nCn
    int res=nCr(2*n,n);
    res=res/(n+1);
    return res;
}