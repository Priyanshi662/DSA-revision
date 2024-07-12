#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute force: 
// Find All permutations, linear search for the current permutation, return the next permutation
 class Solution {
public:
    void printpermutation(vector<int>& nums,vector<vector<int>>& ans,
                            vector<int> curr,vector<bool> vis)
    {
        if(curr.size()==nums.size())
        {
            // when every element is done backtrack stops
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(!vis[j])
            {
                vis[j]=true;
                curr.push_back(nums[j]);
                printpermutation(nums,ans,curr,vis);
                curr.pop_back();
                vis[j]=false;
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> allperm;
        int n=nums.size();
        vector<bool> vis(n,false);
        vector<int> curr;
        vector<int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        printpermutation(v,allperm,curr,vis);
        int i=0;
        for(;i<allperm.size();i++)
        {
            if(allperm[i]==nums)
            {
                break;
            }
        }
        // cout<<i<<endl;
        if(i==(allperm.size()-1))
        {
            // cout<<i<<endl;
            // for(auto it: nums)  cout<<it<<" ";
            sort(nums.begin(),nums.end());
            return;
        }
        else
            nums=allperm[i+1];
        return;
    }
};

// TC: O(n*n!) -> n! is the number of permutations which we find using backtracking
// n is the size of the nums array


// ---- Optimal -----
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step 1 - find the breakpoint - local maximum from the last
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0; i--)
        {
            if(nums[i+1]>nums[i])
            {
                index=i;
                break;
            }
        }
        // highest possible permutation
        if(index==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }

        // Step 2 - find the nearest greater integer on the right

        for(int i=n-1;i>index;i--)
        {
            if(nums[i]>nums[index])
            {
                swap(nums[i],nums[index]);
                break;
            }
        }

        // Step 3 - reverse/sort the array after index

        reverse(nums.begin()+index+1,nums.end());
        
    }
};