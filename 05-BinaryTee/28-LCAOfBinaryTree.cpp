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
    TreeNode* ans=NULL;
    bool solvedfs(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)
            return false;
        int mid=0,left=0,right=0;
        if(root==p|| root==q)
            mid=1;
        left=solvedfs(root->left,p,q);
        right=solvedfs(root->right,p,q);
        if((mid+left+right)>=2)
            ans=root;
        return ((mid+left+right)>0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        solvedfs(root,p,q);
        return ans;
    }
};
// we can even do it without mid, left and right variables 
// by returning the node and null if not p and q are not found in one dfs recursion
TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL || root==p || root==q)
        return root;
    TreeNode* left=NULL,*right=NULL;
    left=lca(root->left,p,q);
    right=lca(root->right,p,q);
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    // if left and right are not null
    return root;
}