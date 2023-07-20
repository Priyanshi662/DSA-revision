#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int target=-nums[i];
            int front=i+1;
            int back=nums.size()-1;
            while(front<back)
            {
                int sum=nums[front]+nums[back];
                if(sum<target)
                    front++;
                else if(sum>target)
                    back--;
                else
                {
                    vector<int> temp={nums[i],nums[front],nums[back]};
                    res.push_back(temp);
                    // roll over the duplicate element from front as well as back
                    while(front<back && nums[front]==temp[1])
                        front++;
                    while(front<back && nums[back]==temp[2])
                        back--;
                }
            }
            // roll over duplicated element of ith loop too
            while(i+1 < nums.size() && nums[i+1]==nums[i])
                i++;
        }
        return res;
    }
};