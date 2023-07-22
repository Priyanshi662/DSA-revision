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
 class Solution {
public:
    TreeNode* deleteUtil(TreeNode* root,int key)
    {
        if(root==NULL)
            return NULL;
        if(root->val < key)
            root->right= deleteUtil(root->right,key);
        else if(root->val > key)
            root->left= deleteUtil(root->left,key);
        else
        {
            if(root->left && root->right)
            {
                TreeNode* temp=root->right;
                while(temp->left!=NULL)
                    temp=temp->left;
                temp->left=root->left;
                return root->right;
            }
            else if(root->left==NULL)
            {
                return root->right;
            }
            else if(root->right==NULL)
            {
                return root->left;
            }
            else
                return NULL;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // here 4 cases -
        // target node has - 
        // 1. only left node ->delete and replace with left node
        // 2. only right node ->delete and right->left=left
        // 3. left and right node -> replace with inorder successor
        // 4. no children
        return deleteUtil(root,key);
    }
};