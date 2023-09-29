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

void bottomviewrec(TreeNode* root,unordered_map<int,int> & res,int vh)
{
    if(root==NULL)
        return ;
    res[vh]=root->val;
    bottomviewrec(root->left,res,vh-1);
    bottomviewrec(root->right,res,vh+1);
}
vector <int> bottomView(TreeNode *root) {
        vector<int> res;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode* curr=q.front().first;
            int vh=q.front().second;
            q.pop();
            mp[vh]=curr->val;
            if(curr->left)
                q.push({curr->left,vh-1});
            if(curr->right)
                q.push({curr->right,vh+1});
        }
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        return res;
    }