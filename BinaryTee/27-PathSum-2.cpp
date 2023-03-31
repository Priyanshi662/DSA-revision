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
    vector<vector<int>> paths;
    void pathSumUtil(TreeNode* root,int target,vector<int> path)
    {
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && target==root->val)
        {
            paths.push_back(path);
            return;
        }
        target=target-root->val;
        pathSumUtil(root->left,target,path);
        pathSumUtil(root->right,target,path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pathSumUtil(root,targetSum,path);
        return paths;
    }
};