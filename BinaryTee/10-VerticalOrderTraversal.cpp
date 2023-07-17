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
// Uses Concept of Top view of Binary tree - horizontal distance from root:
    vector<vector<int>> verticalTraversal(TreeNode* root)   
    {
        if(root==NULL)
            return {};
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode* curr=q.front().first;
            int vh=q.front().second;
            q.pop();
           
           
            mp[vh].push_back(curr->val);
            
            if(curr->left!=NULL)
                q.push({curr->left,vh-1});
            if(curr->right!=NULL)
                q.push({curr->right,vh+1});
        }
        vector<vector<int> > res;
        for(auto it: mp)
        {
            vector<int> temp=it.second;
            sort(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
};