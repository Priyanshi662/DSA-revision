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
    void traversals(TreeNode * root)
    {
        vector<int> in,pre,post;
        stack<pair<TreeNode*,int>> st;
        // 1 -> preorder
        // 2 -> inorder
        // 3 -> postorder
        st.push({root,1});
        while(!st.empty())
        {
            auto p=st.top();
            int state=p.second;
            if(state==1)
            {
                pre.push_back(p.first->val);
                st.top().second++;
                if(p.first->left!=NULL)
                {
                    st.push({p.first->left,1});
                }
            }
            else if(state==2)
            {
                in.push_back(p.first->val);
                st.top().second++;
                if(p.first->right!=NULL)
                {
                    st.push({p.first->right,1});
                }
            }
            else
            {
                post.push_back(p.first->val);
                st.pop();
            }
        }
    }
 };