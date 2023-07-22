#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    // Brute Force : inorder and reverse the vector -> 
    // O(nlogn) and O(h)
    void inorder(TreeNode* root,vector<int> & v)
    {
       if(root==NULL)
       {
           return ;
       }
       if(root->left!=NULL)
       inorder(root->left,v);
       v.push_back(root->val);
       if(root->right!=NULL)
       inorder(root->right,v);
    }
    int kthLargest(TreeNode *root, int K)
    {
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        sort(v.begin(),v.end(),greater<int>());
        return v[K-1];
    }
    // optimal -> O(h+k) and O(h)
    void solve2(TreeNode* root,int k,int &cnt,int &res)
    {
               if(root->right!=NULL)
               solve2(root->right,k,cnt,res);
                cnt=cnt+1;
            if(cnt==k)
                {
                    res=root->val;
                    // cout<<res<<endl;
                    // return;
                }
       
              if(root->left!=NULL)
              solve2(root->left,k,cnt,res);
        
    }
    int kthLargest2(TreeNode *root, int K)
    {
        int cnt=0;
        int res=-1;
       solve2(root,K,cnt,res);
       return res;
    }
};
