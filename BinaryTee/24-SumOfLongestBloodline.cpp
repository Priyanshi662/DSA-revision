// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
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

class Solution
{
public:
    int maxsum=0;
    void solvedfs(TreeNode* root,int sum,int&maxsum,int h,int &maxh)
    {
        if(root==NULL)
    {        
        if(h>maxh)
        {
            maxsum=sum;
            maxh=h;
        }
        else if(h==maxh)
        {
            maxsum=max(sum,maxsum);
        }
        return;
    }
        sum+=root->val;
        solvedfs(root->left,sum,maxsum,h+1,maxh);
        solvedfs(root->right,sum,maxsum,h+1,maxh);
    }
    int sumOfLongRootToLeafPath(TreeNode *root)
    {
        int sum=0;
        int maxsum=0;
        int h=0;
        int maxh=0;
        solvedfs(root,sum,maxsum,h,maxh);
        return maxsum;
    }
};