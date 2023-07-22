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

class Solution{
public:
// Using extra space : Map
// concept of horizontal distance from the root of the tree
    void solve(TreeNode* root,vector<int> &res)
    {
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int vh=q.front().second;
            q.pop();
            if(mp[vh]==0)
                mp[vh]=temp->val;
            if(temp->left!=NULL)
                q.push({temp->left,vh-1});
            if(temp->right!=NULL)
                q.push({temp->right,vh+1});
        }
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
    }
    //Function to return a list of Treenodes visible from the top view 
    //from left to right in Binary Tree.
     // here level wise left and right wont work because 
        // top view will be like a flattened tree with only top Treenodes visible
        // for example 
        //           1
        //         /   \ 
        //       2      4
        //      / \    / \ 
        //     5  6   7   8
        //  Top view - 5 2 1 4 8
        // so here we need a vertical height
// Using Dequeue instead of map and queue:
    void solveOptimal(TreeNode* root,vector<int> &res)
    {
        deque<int> dq;
        int l=0;
        int r=0;  
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        dq.push_back(root->val);
        while(!q.empty())
        {
            TreeNode* curr=q.front().first;
            int vh=q.front().second;
            q.pop();
            if(vh>r)
            {
                dq.push_back(curr->val);
                r=vh;
            }
            if(vh<l)
            {
                dq.push_front(curr->val);
                l=vh;
            }
            if(!curr->left)
            {
                q.push({curr->left,vh-1});
            }
            if(!curr->right)
            {
                q.push({curr->right,vh+1});
            }
        }
        while(!dq.empty())
        {
            res.push_back(dq.front());
            dq.pop_front();
        }
        
    }
    vector<int> topView(TreeNode* root)
    {
        vector<int> res;
        solve(root,res);
        return res;
    }
};