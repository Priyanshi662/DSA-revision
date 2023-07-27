#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
// Brute Force: O(n^2)
    vector<int> finalPrices(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<=arr[i])
                {
                    mini=arr[j];
                    break;
                }
            }
            if(mini==INT_MAX)
                ans.push_back(0);
            else
                ans.push_back(-mini);
        }
        for(int i=0;i<n;i++)
            ans[i]=arr[i]+ans[i];
        return ans;
    }
    // using stack:
     vector<int> finalPrices1(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>arr[i])
                st.pop();
            int x=arr[i];
            if(!st.empty())
                ans[i]=(-st.top());
            st.push(arr[i]);
        }
        for(int i=0;i<n;i++)
            ans[i]=ans[i]+arr[i];
        return ans;
    }
};