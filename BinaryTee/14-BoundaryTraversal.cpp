#include <bits/stdc++.h>
using namespace std;
// TreeNode class
class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    // Constructor
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
};
class Solution {
public:
// Using stack : TC : O(n)  SC:O(n)
    bool isLeaf(TreeNode* root)
    {
        return (root->left==NULL && root->right==NULL);
    }
    void addLeafNodes(TreeNode* root,vector<int>& res)
    {
        if(isLeaf(root))
            res.push_back(root->val);
        else
        {
            if(root->left!=NULL)
                addLeafNodes(root->left,res);
            if(root->right!=NULL)
                addLeafNodes(root->right,res);
        }
    }
    vector<int> boundaryTraversal(TreeNode* root)
    {
        if(root==NULL)
            return {};
        TreeNode* node=root;
        vector<int> v;
        while(node!=NULL)
        {
            if(!isLeaf(node))
            {
                v.push_back(node->val);
            }
            if(node->left)
            {
                node=node->left;
            }
            else
            {
                node=node->right;
            }
        }
        addLeafNodes(root,v);
        node=root->right;
        // Stack is used to help store right nodes in reverse order in result vector
        stack<int> st;
        while(node!=NULL)
        {
            if(!isLeaf(node))
            {
                st.push(node->val);
            }
            if(node->right)
                node=node->right;
            else
                node=node->left;
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
// Using Recursion:
    vector<int> res,right;
    void solve(TreeNode* root,int state)
    {
        // add in res if left node or leaf node
        if(root==NULL)
            return;
        if(state==1)
            res.push_back(root->val);
        else if(state==2)
            right.push_back(root->val);
        else if(root->left==NULL && root->right==NULL)
            res.push_back(root->val);
        solve(root->left,state==1? 1: (state==2 &&!root->right ? 2:0));
        solve(root->right,state==2?2: (state==1 && !root->left ? 1:0));
    }
    vector<int> BoundaryTraversal(TreeNode* root)
    {
        // states - 1->left, 0->leaf, 2->right
        // Use DFS :
        res.push_back(root->val);
        solve(root->left,1);
        solve(root->right,2);

    }
};
