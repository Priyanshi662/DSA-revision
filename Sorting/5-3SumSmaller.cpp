// OJ: https://leetcode.com/problems/3sum-smaller/
// Time: O(N^2)
// Space: O(1)
#include <vector>
#include <algorithm>
using namespace std;

// the triplets may not be unique
class Solution {
private:
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int i = start, j = nums.size() - 1, ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                ++i;
            } else --j;
        }
        return ans;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int N = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        return ans;
    }
};