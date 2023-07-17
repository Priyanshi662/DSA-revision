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
// The diameter of a binary tree can be of present in 3 ways in a binary tree
// 1. if the tree is left skewed it might be present in left subtree
// 2. if the tree is right skewed it might be present in right subtree
// 3. the longest path between the leaf nodes in left and right subtree passing through the root
//     
int height(TreeNode * root, int &diameter)
{
    if(root==NULL)
        return 0;
    int lh,rh;
    lh=height(root->left,diameter);
    rh=height(root->right,diameter);
    diameter=max(lh+rh,diameter);
    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        // here diameter is calculated at each step of the height recursive call
        // thereby saving extra space
        height(root,diameter);
        return diameter;
    }
};