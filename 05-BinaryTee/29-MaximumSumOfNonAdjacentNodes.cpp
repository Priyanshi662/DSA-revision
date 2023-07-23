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
 class Solution
 {
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    typedef pair<int,int> pii;
    pii solve(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        pii left=solve(root->left);
        pii right=solve(root->right);
        pii ans;
        // ans.first has sum when root->val is added then left and right child are not added
        ans.first= root->val + left.second+right.second;
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    int getMaxSum(TreeNode *root) 
    {
        pii ans=solve(root);
        return max(ans.first,ans.second);
    }
 };