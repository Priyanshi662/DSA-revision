#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums.size()==1 && target==nums[0])
            return 0;
        int low=0;
        int high=n-1;
        // there are three cases
        // the mid value and target is in the same side of the increasing sequence either left increasing or right increasing 
        // the target is in the left ->target>nums[0]
        // the target is in the right ->target<nums[0]
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int comparator=nums[mid];
            if((target<nums[0] && nums[mid]<nums[0]) ||( target>=nums[0] && nums[0]<=nums[mid]))
            {
                comparator=nums[mid];
            }
            else
            {
                if(target<nums[0])
                    comparator=INT_MIN;
                else 
                    comparator=INT_MAX;
            }
            if(target==comparator)
                return mid;
            if(target>comparator)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};