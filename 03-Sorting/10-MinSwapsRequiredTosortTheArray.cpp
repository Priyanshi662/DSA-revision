#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// this is wrong approach because the swapped element might not 
// be at it correct position and might require further swapping
int minSwaps(vector<int>&nums)
{
    vector<int> cpy;
    for(int i=0;i<nums.size();i++)
        cpy.push_back(nums[i]);
    sort(cpy.begin(),cpy.end());
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=cpy[i])
            count++;
    }
    return (count+1)/2;
}
// with sorting and extra space(map)
int minSwaps(vector<int> &nums)
{
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]=i;
    sort(nums.begin(),nums.end());
    int count=0;
    for(int j=0;j<nums.size();j++)
    {
        // while loop because we'll keep swapping till the index becomes j
        while(mp[nums[j]]!=j)
        {
            int ind=mp[nums[j]];
            swap(nums[j],nums[ind]);
            count++;
        }
    }
    return count;
}

// using concept of graph
int minSwaps(vector<int> & nums)
{
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        mp[nums[i]]=i;
    sort(nums.begin(),nums.end());

    vector<bool> visited(nums.size(),false);
    int ans=0;
    for(int j=0;j<nums.size();j++)
    {
        // self loop
        if(visited[j] && mp[nums[j]]==j)
            continue;
        // connected with j and mp[nums[j]]
        else
        {
            int cyclelen=0;
            int k = j;
            while(visited[k]==false)
            {
                visited[k]=true;
                cyclelen++;
                k=mp[k];
            }
            ans+=(cyclelen-1);
        }
    }
    return ans;
}