#include <iostream>
#include <vector>
#include <stack>
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
        // The problem with this solution is that it is checking the immediate parent and not the parent from 
        // the root so it will give wrong answer when the input is of the form [5,4,6,null,null,3,7]
    }
    // BRUTE FORCE:
    // Sort -> find inorder and see if their is any descending order in the inorder
    vector<int> nodes;
    void inorder(TreeNode* root) {
        if (root->left) inorder(root->left);
        nodes.push_back(root->val);
        if (root->right) inorder(root->right);
    }
    bool isValidBST1(TreeNode* root) {
        inorder(root);
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i] >= nodes[i+1]) return false;
        }
        return true;
    }

    // optimal :
    // Iterative way
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        stack<TreeNode*> st;
        TreeNode* prev=NULL;
        while(root|| !st.empty())
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            root= st.top(); st.pop();
            // prev can be - 
            // 1. left node -> checked with root
            // 2. parent node-> checked with right(popped from stack when NULL encountered)
            if(prev!=NULL && root->val<=prev->val)
                return false;
            prev=root;
            root=root->right;
        }
        return true;
    }

};