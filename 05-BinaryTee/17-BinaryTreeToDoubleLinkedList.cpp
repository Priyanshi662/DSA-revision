// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
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
    void solve(TreeNode* root,TreeNode* &head,TreeNode* &prev)
    {
        if(root==NULL)
            return;
        solve(root->left,head,prev);
        root->left=prev;
        if(prev==NULL)
            head=root;
        else
            prev->right=root;
        prev=root;
        solve(root->right,head,prev);
    }
    TreeNode* BinaryTreeToDLL(TreeNode* root)
    {
        TreeNode* head=NULL;
        TreeNode* prev=NULL;
        solve(root,head,prev);
        return head;
    }
};