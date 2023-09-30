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
typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll maxwidth=0;
        while(!q.empty()) 
        {
            ll n=q.size();
            ll leftmost=q.front().second;
            ll index=leftmost;
            ll rightmost=q.back().second;
            maxwidth=max(maxwidth,(rightmost-leftmost+1));
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                index=p.second;
                index-=leftmost;
                if(p.first->left!=NULL)
                {
                    q.push({p.first->left,(ll)2*index+1});
                }
                if(p.first->right!=NULL)
                {
                    q.push({p.first->right,(ll)2*index+2});
                }
                q.pop();
            }
        }   
        return maxwidth;
    }
};