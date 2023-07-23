#include <iostream>
#include <stack>
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
// The brute force would be to store inorder in a vector and return the (k-1)th term in that vector
// The optimal is ->
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            k--;
            root=st.top();
            st.pop();
            if(k==0)
            {
                return root->val;
            }
            root=root->right;
        }
        return root->val;
    }
};