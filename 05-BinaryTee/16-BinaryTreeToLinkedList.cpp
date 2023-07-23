// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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
// Using Extra space -
    // Time complexity - O(n)
    // Space complexity - O(h)
    void flatten(TreeNode* root) {
        // This is iterative version :
        if(root==NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev=new TreeNode(-1);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();
            // The right most should be last node to be added
            if(temp->right) st.push(temp->right);
            // The left most node in left subtree should be connected with the root->right
            if(temp->left)  st.push(temp->left);
            prev->left=NULL;
            // prev stores the root in right manner
            prev->right=temp;
            prev=temp;
        }
    }
    // Using morris traversal , we can reduce the space complexity to O(1)
    void flatten(TreeNode* root)
    {
        if(root==NULL)
            return ;
        while(root)
        {
            // if it is a middle node then left child's rightmost node should be connected to the root->right
            if(root->left && root->right)
            {
                TreeNode* temp=root->left;
                while(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                // this will help in traversing the right subtree
                temp->right=root->right;
            }
            // now adjust the root->right= root->left 
            if(root->left)
                root->right=root->left;
            root->left=NULL;
            // move to the right node of the tree:
            root=root->right;
        }
    }
};