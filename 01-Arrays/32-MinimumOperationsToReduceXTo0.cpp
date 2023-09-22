#include <vector>
#include <limits.h>
using namespace std;
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/?envType=daily-question&envId=2023-09-20
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0;
        int j=0;
        int totalsum=0;
        for(int i=0;i<nums.size();i++)
            totalsum+=nums[i];
        if(totalsum<x)
            return -1;
        int minops=INT_MAX;
        int currops=0;
        int n=nums.size();
        int targetsum=totalsum-x;
        int currsum=0;
        while(j<n)
        {
            currsum+=nums[j];
            while(i<=j && currsum>targetsum)
            {    
                currsum-=nums[i];
                i++;
            }
            if(currsum==targetsum)
            {
                currops=n-(j-i+1);
                minops=min(minops,currops);
            }
            
            j++;
        }
        if(minops==INT_MAX)
            return -1;
        return minops;
    }
};