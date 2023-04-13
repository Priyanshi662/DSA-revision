#include <iostream>
#include <vector>
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
    // WRONG SOLUTION
    bool isValidBSTWrong(TreeNode* root) {
        if(root==NULL)
            return true;
        bool l=isValidBSTWrong(root->left);
        bool r=isValidBSTWrong(root->right);
        bool z=true;
        if(root->left!=NULL)
            z=(root->left->val<root->val);
        if(root->right!=NULL)
            z=z&&(root->right->val>root->val);
        if(l and r and z)
            return true;
        else
            return false;
        // The problem with this solution is that it is checking the immediate parent and not the parent from the root so it will give wrong answer when the input is of the form [5,4,6,null,null,3,7]
    }

};