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
void inorder(TreeNode* root,vector<int> &in)
{   
    if(root==NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
int minSwaps(TreeNode* root)
{
    vector<int> in;
    inorder(root,in);
    vector<int> cpy=in;
    sort(in.begin(),in.end());
    int count=0;
    for(int i=0;i<in.size();i++)
    {
        if(in[i]!=cpy[i])
            count++;
    }
    return count;
}
};