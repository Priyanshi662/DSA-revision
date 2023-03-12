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

    void inorderiterative(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
            return ;
        stack <TreeNode*> st;
        TreeNode* curr=root;
        // curr is used to traverse the tree and adding nodes to the stack
        while(curr!=NULL || st.empty()!=true)
        {
            // push left children till no left child exists 
            // using it inside the loop becaus ethe right nodes might have left child 
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
    }   
    void inorder(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
            return ;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};