#include <iostream>
#include <stack>
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

class Solution{
public:
int ans=0;
    vector<int> solve(TreeNode* root)
    {   
        //returns = {minimum, maximum, count(if not valid return -1)}
        if(root==NULL)
            return {INT_MAX, INT_MIN, 0};
        vector<int> left=solve(root->left);
        vector<int> right=solve(root->right);
        bool isValid=(left[2]!=-1)&&(right[2]!=-1)&&(left[1]<=root->val && right[0]>=root->val);
        if(isValid)
        {
            ans=max(ans,(left[2]+right[2]+1));
        }
        int first = left[2]==-1? root->val : left[1];
        int second= right[2]==-1? root->val : right[0];
        int third = isValid? 1+left[2]+right[2] : -1;
        return  {first,second,third};
    } 
    int LargestBst(TreeNode* root)
    {
            solve(root);
            return ans;
    }    
};