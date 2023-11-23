#include <vector>
#include <queue>
using namespace std;
class Solution {
public:

    void buildGraph(vector<vector<int>> &edges,vector<vector<int>>&adj,int n)
    {
        adj.resize(n + 1);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    // IF there is no limitation of the order of the edges:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<bool> vis(n+1,false);
        vector<int> parent(n+1,-1);
        vector<vector<int>> adj;
        buildGraph(edges,adj,n);
        vector<int> res;
        queue<int> q;
        q.push(1);
        parent[1]=-1;
        vis[1]=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto it: adj[curr])
            {
                if(vis[it]==false)
                {
                    q.push(it);
                    vis[it]=true;
                    parent[it]=curr;
                }
                else
                {
                    if(parent[curr]!=it)
                    {
                        res.push_back(curr);
                        res.push_back(it);
                        return res;
                    }
                }
            }
        }
        return res;
    }
};


// Using union and find function:
class Solution {
public:
    int find(int node, vector<int> &parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node], parent); // Path Compression
    }

    bool unionfunc(int n1, int n2, vector<int> &parent, vector<int> &rank) {
        int p1 = find(n1, parent);
        int p2 = find(n2, parent);
        
        if (p1 == p2)
            return false;
        else {
            if (rank[p1] < rank[p2]) {
                rank[p2] += rank[p1];
                parent[p1] = p2;
            } else {
                rank[p1] += rank[p2];
                parent[p2] = p1;
            }
            return true;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        vector<int> ranks(n + 1, 1);
        
        for (auto it : edges) {
            if (!unionfunc(it[0], it[1], parent, ranks))
                return it;
        }
        return {}; // If no redundant connection found
    }
};
