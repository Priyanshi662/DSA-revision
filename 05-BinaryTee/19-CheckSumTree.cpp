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
    int  sum(TreeNode* root,int & flag)
    {
        if(root==NULL)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        int left=sum(root->left,flag);
        int right=sum(root->right,flag);
        
    }
    bool isSumTree(TreeNode* root)
    {
        int flag=false;
        sum(root,flag);
        return flag;
    }
};