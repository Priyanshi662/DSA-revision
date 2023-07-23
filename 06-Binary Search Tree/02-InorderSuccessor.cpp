#include <iostream>
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
    TreeNode* ans=NULL;
    int flag=0;
    TreeNode* solve(TreeNode* root,TreeNode* ele)
    {
        if(root==NULL)
            return ;
        solve(root->left,ele);
        if(flag && ans==NULL)
        {
            ans=root;
        }
        if(root==ele)
        {
            flag=true;
        }
        solve(root->right,ele);
    }
    TreeNode* solve2(TreeNode* root,TreeNode* e)
    {
        if(root==NULL)
            return NULL;
        if(root->val<=e->val)
            return solve2(root->right,e);
        else
        {
            TreeNode* left=solve2(root->left,e);
            // if successor of left is NULL => right of left is NULL then
            if(left==NULL)
                return root;
            else
                return left;
        }
    }
    TreeNode* InorderSuccessor(TreeNode* root,TreeNode* f)
    {
        return solve2(root,f);
        // solve(root,f);
        // return ans;
    }
 };
