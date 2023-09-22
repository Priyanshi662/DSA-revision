#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    
    int findmaxcommonlength(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == nums1.size() || j == nums2.size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int result = 0;
        if (nums1[i] == nums2[j]) {
            result = 1 + findmaxcommonlength(nums1, nums2, i + 1, j + 1);
        }
        
        dp[i][j] = result;
        return result;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n, vector<int>(m, -1));
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxLen = max(maxLen, findmaxcommonlength(nums1, nums2, i, j));
            }
        }
        return maxLen;
    }
};
