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
    vector<vector<int>> DiagonalTraversal(TreeNode* root)
    {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> v;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                while(curr!=NULL)
                {
                    temp.push_back(curr->val);
                    if(curr->left!=NULL)
                        q.push(curr->left);
                    curr=curr->right;
                }
            }
            v.push_back(temp);
        }
        return v;
    }

};