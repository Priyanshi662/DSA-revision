#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
// Using extra space -> 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<multiset<int>> st;
        unordered_set<int> vis;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x=target-(nums[i]+nums[j]+nums[k]);
                    if(vis.count(x)>0)
                        st.insert(multiset<int>{nums[i],nums[j],nums[k],x});
                }
            }
            vis.insert(nums[i]);
        }
        vector<vector<int>> ans;
        for(auto it:st)
        {
            vector<int> temp(it.begin(),it.end());
            ans.push_back(temp);
        }
        return ans;
    }
// Using 2 pointer approach ->
 vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int low=j+1;
                int high=n-1;
                long long rem=(long long)target-nums[i]-nums[j];
                while(low<high)
                {
                    int sum=nums[low]+nums[high];
                    if(sum==rem)
                    {
                        temp={nums[i],nums[j],nums[low],nums[high]};
                        res.push_back(temp);
                        low++;
                        high--;
                        while(low<high && nums[low-1]==nums[low])
                        ++low;
                    }
                    else if(sum<rem)
                        low++;
                    else
                        high--;
                }
                while(j+1<n && nums[j]==nums[j+1])
                    ++j;
            }
            while(i+1<n && nums[i]==nums[i+1])
                    ++i;
        }
        return res;
    }
};