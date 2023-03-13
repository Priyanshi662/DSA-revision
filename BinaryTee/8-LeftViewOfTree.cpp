//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// TreeNode class
class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    // Constructor
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
};


// Time complexity -> O(n) as we are traversing all nodes in tree
// Space complexity-> O(n) from recursion stack
// This approach uses preorder traversal but we need to have nextlevel to keep track of levels
// and only take the leftmost element at each level
void solve(TreeNode*root,vector<int>& res,int nextlevel,int &currlevel)
{
    if(root==NULL)
        return;
    if(currlevel<nextlevel)
    {
        // if current level < next level -> this level is traversed for the first time
        res.push_back(root->val);
        currlevel=nextlevel;
    }
    solve(root->left,res,nextlevel+1,currlevel);
    solve(root->right,res,nextlevel+1,currlevel);
}

// Iterative level order method: O(n) and O(n)

vector<int> solve2(TreeNode* root)
{
    if(root==NULL)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            if(i==0)
                res.push_back(q.front()->val);
                TreeNode* curr=q.front();
                q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
vector<int> leftView(TreeNode *root)
{
   vector<int> res;
   int currlevel=0;
//   we have to take the leftmost element at each level
// this might or might not be the left subtree from the root
   solve(root,res,1,currlevel);
   return res;
}

int main(){
    /*
    Building the following Binary Tree
            1
           / \
          2   3
         /   / \
        4   5   6
         \   \   \
          7   8   9
             /
            10
    */
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);
    
    // Calling the leftView function
    vector<int> res=leftView(root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    
    return 0;
}
