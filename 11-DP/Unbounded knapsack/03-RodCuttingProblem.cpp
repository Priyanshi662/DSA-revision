// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int recurCutRod(int price[],int n,int index)
{
    if(index==0)
        return n*price[0];
    int notcut=recurCutRod(price,n,index-1);
    int cut=INT_MIN;
    // the length of current rod will be index+1
    if(index+1<n)
        cut=price[index]+recurCutRod(price,n,index);
    return max(cut,notcut);
}
int cutRod(int price[], int n) {
    int len[n];
    for(int k=0;k<n;k++)
    {
        len[k]=k+1;
    }
    // first index is the length that can be cut (from the length array)
    // second index is the already cut length 
    // dp will store the profit at that length
    int dp[n+1][n+1];
    // if rod length=0 -> no profit
    // if already cut=0 -> no profit
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(len[i-1]>j)
            {
                dp[i][j]=max(price[i-1]+dp[i-1][j-len[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][n];
}