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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty())
        {
            vector<int> v;
            int n=q.size();
            // pushing nodes at each level
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            // even level node will be reversed
            if(lvl%2!=0)
                reverse(v.begin(),v.end());
            res.push_back(v);
            lvl++;
        }
        return res;
    }
};
