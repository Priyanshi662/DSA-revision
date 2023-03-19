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
    TreeNode* solve(string s)
    {
        if(s=="")
            return nullptr;
        // 1. find the first occurence of '('
        int pos=s.find('(');
        if(pos==s.npos)
            return new TreeNode(stoi(s.substr(0,pos)));
        TreeNode* root=new TreeNode(stoi(s.substr(0,pos)));
        // start stores the index of left subtree or right subtree 
        int start=pos;
        // counts the number of brackets open -> if all brackets get closed its a subtree
        int count=0;
        for(int i=pos;i<s.size();i++)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
                count--;
            if(count==0)
            {
                if(start==pos)
                {
                    // i-start-1 will be removing the last bracket at the end
                    root->left=solve(s.substr(start+1,i-start-1));
                    start=i+1;
                }
                else
                {
                    root->right=solve(s.substr(start+1,i-start-1));
                }
            }
        }
        return root;
    }
    TreeNode* strtoTree(string s)
    {
        if(s=="")
            return NULL;
        return solve(s);
    }
};