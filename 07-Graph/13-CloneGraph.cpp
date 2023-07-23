#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
// USING BFS :
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        // we have to use unordered map in this to keep a check on nodes that are already created i.e the nodes which are connected to more than one node thus traversed more than once in bfs
        Node* first=new Node(node->val,{});
        mp[node]=first;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            for(auto adj:curr->neighbors)
            {
                if(mp.find(adj)==mp.end())
                {
                    mp[adj]=new Node(adj->val,{});
                    q.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
    // Using DFS:
    unordered_map<Node*,Node*> mp2;
    Node* cloneGraphDFS(Node* node)
    {
        if(node==NULL)
            return NULL;

        if(mp.find(node)==mp.end())
        {    
            mp[node]=new Node(node->val,{});

            for(auto adj:node->neighbors)
            {
                Node* newadj=cloneGraphDFS(adj);
                mp[node]->neighbors.push_back(newadj);
            }
        }
        return mp[node];
    }
};