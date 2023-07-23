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
    vector<int> solve(TreeNode* root)
    {
        if(root=NULL)
            return {};
        stack<TreeNode*> st;
        TreeNode* prev=NULL;
        TreeNode* curr=NULL;
        TreeNode* node=root;
        while(node!=NULL || !st.empty())
        {
            while(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            curr=st.top();
            st.pop();
            if(prev!=NULL)
                prev->right=curr;
            curr->left=prev;
            prev=curr;
            node=curr->right;
        }
    }
};