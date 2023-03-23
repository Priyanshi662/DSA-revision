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
    TreeNode* buildutil(vector<int>& preorder,vector<int>& inorder,int si,int ei,int sp,int ep)
    {
        if(sp>ep || si>ei)
            return NULL;
        int i;
        for(i=si;i<=ei;i++)
        {
            if(preorder[sp]==inorder[i])
                break;
        }
        TreeNode* curr=new TreeNode(preorder[sp]);
        // inorder - [[5,4,2,6][1][3,9,7,8]]
        // preorder- [[1][2,4,5,6][3,7,9,8]]
        curr->left=buildutil(preorder,inorder,si,i-1,sp+1,sp+(i-si));
        curr->right=buildutil(preorder,inorder,i+1,ei,sp+(i-si)+1,ep);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=buildutil(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
        return root;
    }
};