#include <iostream>
#include <set>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 struct Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
    TreeNode* lcaOptimal(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)
            return root;
        int mini=min(p->val,q->val);
        int maxi=max(p->val,q->val);
        while(root!=NULL)
        {
            if(root->val>=mini && root->val<=maxi)
                return root;
            else if(root->val<=mini)
                root=root->right;
            else if(root->val>=maxi)
                root=root->left;
        }
        return NULL;
    }
    // Lowest Common Ancestor Part - iii)
    // https://leetcode.ca/2020-06-06-1650-Lowest-Common-Ancestor-of-a-Binary-Tree-III/
    // 1st method is to use a set -> where the lca will be the first common node traversing from p to q
    Node* lcapart3(Node* p,Node* q)
    {
        set<Node*> s;
        Node* temp=p;
        while(temp)
        {
            s.insert(temp);
            temp=temp->parent;
        }
        temp=q;
        while(temp)
        {
            if(s.find(temp)!=s.end())
            {
                break;
            }
            temp=temp->parent;
        }
        return temp;
    }
    Node* lcapart3Approach2(Node* p,Node* q)
    {
        Node* a = p, *b = q;
        while (a != b) {
            a = a->parent == NULL ? q : a->parent;
            b = b->parent == NULL ? p : b->parent;
        }
        return a;
    }
};
