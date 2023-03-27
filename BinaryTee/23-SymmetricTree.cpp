// https://leetcode.com/problems/symmetric-tree/description/
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
// recursive : has greater run time:
bool solve(TreeNode* l,TreeNode* r)
{
    if(l==NULL && r==NULL)
        return true;
    if(l==NULL || r==NULL)
        return false;
    if(l->val!=r->val)
        return false;
    return (solve(l->left,r->right) && solve(l->right,r->left));
}
// Iterative : takes more space
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root->left);
        q2.push(root->right);
        TreeNode* left,*right;
        while(!q1.empty() && !q2.empty())
        {
            left=q1.front();
            q1.pop();
            right=q2.front();
            q2.pop();
            // No need to push in queue if the nodes are null
            if(left==NULL && right==NULL)
                continue;
            if(left==NULL || right==NULL)
                return false;
            if(left->val!=right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};