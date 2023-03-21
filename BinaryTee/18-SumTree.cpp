// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
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

class Solution {
  public:
    int SumUtil(TreeNode* root)
    {
        if(root==NULL)  
            return 0;
        int x=root->val;
        int left=SumUtil(root->left);
        int right=SumUtil(root->right);
        root->val=left+right;
        return root->val+x;
    }
    void toSumTree(TreeNode *Treenode)
    {
        SumUtil(Treenode);
    }
};