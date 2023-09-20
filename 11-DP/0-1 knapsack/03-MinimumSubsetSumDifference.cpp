#include <vector>
#include <iostream>
using namespace std;
// using subset sum when we fill the dp
// In the last row , wherever there is 1 it means that sum is a valid subset sum
// this will be our range for s1 and s2 that are two partitions of the array
// maximum subset sum -> sum of the elements
// minimum -> 0 (empty subset)
// half of the valid subsets will be s1, and other half is s2
// since s2=target-s1
// differences will be s2-s1 -> target-2*s1
// find the minimum of these
bool FillValidSums(vector<int> &nums,int target,int n)
{
    vector<bool> prev(target+1,false);
    prev[0]=true;
    vector<bool> curr(target+1,false);
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<target+1;j++)
        {
            if(nums[i-1]<=j)
                curr[j]=prev[j-1]||prev[j-nums[i-1]];
            else
                curr[j]=prev[i-1];
        }
        prev=curr;
    }
    return curr[target];
}
