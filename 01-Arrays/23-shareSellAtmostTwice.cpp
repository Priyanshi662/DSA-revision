#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&price){
    // First we find minimum price and maximum profit from 1st transaction:
    int n=price.size();
    int dp[n]={0};
    int mincp=price[0];
    for(int i=1;i<n;i++)
    {
        mincp=min(mincp,price[i]);
        // For Maximum Profit :
        dp[i]=max(dp[i-1],price[i]-mincp);
    }
    // Secondly we find the maximum selling price for 2nd transaction 
    // which gives maximum profit for both transactions Based on previous day profit:
    int ans=0;
    int maxsp=price[n-1];
    for(int i=n-1;i>0;i--)
    {
        maxsp=max(maxsp,price[i]);
        ans=max(ans,dp[i-1]+(maxsp-price[i]));
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter Number of Share Prices during the day : ";
    cin>>n;
    vector<int> price(n);
    cout<<"Enter Share Prices : ";
    for(int i=0;i<n;i++) cin>>price[i];
    cout<<maxProfit(price)<<endl;
}