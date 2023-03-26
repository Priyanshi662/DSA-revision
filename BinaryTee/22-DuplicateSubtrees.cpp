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
    unordered_map<string,int> mp;
    vector<TreeNode*> res;
    string dfs(TreeNode* root)
    {
        // this function is basically serializing the tree and storing all the subtrees in the way
        if(root==NULL)
            return "#";
            // commas are necessary for the proper ordering of the nodes in the subtree
        string s=to_string(root->val)+','+dfs(root->left)+','+dfs(root->right);
        if(mp[s]==1)
            res.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};