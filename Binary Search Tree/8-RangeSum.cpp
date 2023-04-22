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
    int solve(TreeNode* node,int low,int high)
    {
        int x1=0,x2=0,x3=0;
        if(node==NULL)
            return 0;
        if(node->val < low)
            x1 = solve(node->right,low,high);
        if(node->val > high)
            x2 = solve(node->left,low,high);
        if(node->val >= low && node->val<=high)
        {
            x1 = solve(node->left,low,high);
            x2 = solve(node->right,low,high);
            x3 = node->val;
        }
        return x1+x2+x3; 
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};