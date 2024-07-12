#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums,int k)
{
    int n=nums.size();
    // brute force:
    vector<int> cpy(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        nums[(i+k)%n]=cpy[i];
    }
    // Optimal:
    reverse(nums.begin(),nums.begin()+(n-k));
    reverse(nums.begin()+(n-k),nums.end());
    reverse(nums.begin(),nums.end());

}