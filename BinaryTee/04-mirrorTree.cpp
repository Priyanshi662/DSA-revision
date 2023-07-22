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
    TreeNode* invertTreeITERATIVE(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            swap(curr->left,curr->right);
            // after swapping the left node will be the one according to the result in a level order
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        return root;
    }
    TreeNode* invertTree(TreeNode* root)
    {
        // Optimal :
        if(root!=NULL)
        {
            if(root->left!=NULL || root->right!=NULL)
                swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};