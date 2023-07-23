#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution{
public:
    int sumSubtree(TreeNode* root,int &maxsum)
    {
        if(root==NULL)
            return 0;
        int left=sumSubtree(root->left,maxsum);
        int right=sumSubtree(root->right,maxsum);
        int curr_sum=root->val+left+right;
        maxsum=max(maxsum,curr_sum);
        return curr_sum;
    }
    int MaxSumSubtree(TreeNode* root)
    {
        int maxsum=INT_MIN;
        sumSubtree(root,maxsum);
        return maxsum;
    }
};