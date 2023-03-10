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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Corner case
        if(root==NULL)
            return {};
        vector<vector<int>> res;
        // we will take queue because we have to traverse level wise where the node which is pushed first is added to the answer first
        queue<TreeNode*> q;
        // Level 1 ->root
        q.push(root);
        while(!q.empty())
        {
            vector<int> levelNodes;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                levelNodes.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            res.push_back(levelNodes);
        }
        return res;
    }
};