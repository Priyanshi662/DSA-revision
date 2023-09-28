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
    TreeNode* findInorderPredecessor(TreeNode* node)
    {

    }
    // every node is visted at most 3 times -> constant space complexity and O(n33)
    vector<int> morrisTraversal(TreeNode* root)
    {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr!=NULL)
        {   
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                // point the inorder predecessor to the current node
                // so that we can visit the current node after visiting the left node
                TreeNode* pred=findInorderPredecessor(curr);
                if(pred->right==NULL)
                {
                    // this means that we have not created a thread to the current node
                    // traversed for the first time
                    pred->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pred->right=NULL;
                    // already traversed
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
};