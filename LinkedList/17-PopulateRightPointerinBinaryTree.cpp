#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
// Using extra space
// time complexity : O(n)
    Node* levelOrder(Node* root)
    {
        if(root==NULL)
            return NULL;
        // We will use right to left Level order traversal because
        // we need to point the rightmost node's next to null
        // push the right child of the current node
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* nextRight=NULL;
            for(int i=q.size();i>0;i--)
            {
                Node* temp=q.front();
                q.pop();
                temp->next=nextRight;
                nextRight=temp;
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(temp->left!=NULL)
                    q.push(temp->left);
            }
        }
        return root;
    }
    Node* connect(Node* root) {
        root=levelOrder(root);
        return root;
    }
};
// Without using extra space but recursion stack space
Node* connectDFS(Node* root) {
        if(!root) return nullptr;
        auto L = root -> left, R = root -> right, N = root -> next;
        if(L) {
            L -> next = R;                                // next of root's left is assigned as root's right
            if(N) R -> next = N -> left;                  // next of root's right is assigned as root's next's left (if root's next exist)
            connectDFS(L);                                   // recurse left  - simple DFS 
            connectDFS(R);                                   // recurse right
        }
        return root;
    }