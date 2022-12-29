#include <bits/stdc++.h>
using namespace std;
int mincoinWRONG(vector<int>nums, int amount)
	{
        // does not work because we have to minimize the number of coins
	    // and minimization could be possible with lower denomination coins
	    //For example : amount :12, Arr :1 2 4 5 6 8 9
		// correct answer would be- 4,8 ->2
		// it gives answer as - 9,2,1->3
		// That is why we need to use backtracking with greedy
	    int amtleft=amount;
	    int n=nums.size();
	    int coins=0;
	    for(int i=n-1;i>=0;i--)
	    {
	        if(nums[i]<=amtleft)
	        {
	            int f=amtleft/nums[i];
	            coins+=f;
	            amtleft=amtleft-(f*nums[i]);
	        }
	       
	    }
	    if(amtleft!=0)
	    return -1;
	    return coins;
	}
int mincoinbruteforce(vector<int> coins,int n,int A)
{
    // recursive greedy Brute Force technique 
    if(A==0)
        return 0;
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=A)
        {
            int subres=mincoinbruteforce(coins,n,A-coins[i]);
            if(subres!=INT_MAX && subres+1< res)
            {
                // including coins[i] and subres if it is less than A
                res=subres+1;
            }
        }
    }
    return res;
}
// TC : O(2^n)
// SC : O(n)
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    int n=nums.size();
	    vector<int> dp(amount+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=amount;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(nums[j]<=i)
	            {
	                dp[i]=min(dp[i],1+dp[i-nums[j]]);
	            }
	        }
	    }
	    return dp[amount]>amount? -1: dp[amount];
	}
};

// TC : O(amount*n)
// SC : O(amount)
int main(){
    int n, amount;
    cout<<"Enter number of coin denominations and amount : ";
    cin >> n >> amount;
    vector<int>nums(n);
    cout<<"Enter the denominations of coins : ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    Solution ob;
    int ans = ob.MinCoin(nums, amount);
    cout<<"The minimum number of coins needed are : ";
    cout << ans <<"\n";
	return 0;
}
