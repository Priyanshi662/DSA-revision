#include <iostream>
#include <vector>
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
    bool findPath(TreeNode* root,TreeNode* p,vector<TreeNode*> v)
    {   
        if(root==NULL)  return false;
        v.push_back(root);
        if(root->val ==p->val || findPath(root->left,p,v) || findPath(root->right,p,v))
            return true;
        // removing the root value because it is not in the actual path
        v.pop_back();
        return false;
    }
    // Using LCA concept:
    int getDistance(TreeNode* root,int val)
    {
        if(root==NULL)
            return -1;
        if(root->val == val)
            return 0;
        int leftdist=getDistance(root->left,val);
        int rightdist=getDistance(root->right,val);
        int dist=max(leftdist,rightdist);
        return dist>=0? dist+1:-1;
    }
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode* left=NULL,*right=NULL;
        left=lca(root->left,p,q);
        right=lca(root->right,p,q);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        // if left and right are not null
        return root;
    }
    int findDistance2(TreeNode*root ,TreeNode* p,TreeNode*q)
    {
        if(root==NULL)  
            return -1;
        if(p==q)
            return 0;
        TreeNode* commonparent=lca(root,p,q);
        return max(getDistance(commonparent,p->val),getDistance(commonparent,q->val));
    }
    // By finding distance from root and subtracting common distance
    int findDistance(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(p==q)
            return 0;
        vector<TreeNode*> a,b;
        // find path of root to p
        findPath(root,p,a);
        // find path of root to q
        findPath(root,q,b);
        int i=0;
        while(i<a.size() && i<b.size() && a[i]==b[i]) i++;
        // counting edges in common path
        return (a.size()+b.size()-(2*i));
    }
 };
