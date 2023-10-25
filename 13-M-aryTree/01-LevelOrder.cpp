#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void findlevelOrder(Node* root,vector<Node*> &res)
{
    queue<Node*> q;
    res.clear();
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        Node* curr=q.front();
        q.pop();
        res.push_back(curr);
        for(auto it:curr->children)
            q.push(it);
    }
}
vector<Node*> serialize(vector<Node*> nodes)
{
    set<Node*> res;
    for(auto it: nodes)
    {
        for(auto child:it->children)
        {
            if(child!=NULL)
                res.insert(child);
        }
    }
    Node* parent;
    for(auto it: nodes)
    {
        if(res.find(it)==res.end())
        {
            parent=it;
            break;
        }   
    }
    findlevelOrder(parent,nodes);
    return nodes;
}
int findRoot(vector<Node*> nodes)
{
    int xorval=0;
    // the every node will be a child node of some other node except the root , so it will get cancelled in xor, root however will be the only node remaining
    for(auto it: nodes)
    {
        xorval^=it->val;
        for(auto child:it->children)
            xorval^=child->val;
    }
    for(auto it:nodes)
    {
        if(xorval==it->val)
            return it->val;
    }
    return -1;
}