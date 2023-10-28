#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// we need to use backtracking because their will be forward edges in a loop and backward edges to bring it back to a single point
// Check for back edges which lead upto the ancestor node of the current node

// Using BFS:
bool bfs(vector<int> adj[],int v,int src,vector<bool> &vis)
{
    vector<int> parent(v,-1);
    queue<int> q;
    q.push(src);
    parent[src]=-1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto it: adj[curr])
        {
            if(vis[it]==true&& it!=parent[curr])
            {
                // it was visited without the parent
                return true;
            }
            else
            {
                vis[it]=true;
                q.push(it);
                parent[it]=curr;
            }
        }
    }
    return false;
}
bool dfs(vector<int> adj[],int v,int src,int parent,vector<bool> &vis)
{
    vis[src]=true;
    
    for(auto it: adj[src])
    {
        if(!vis[it])
        {
            bool res=dfs(adj,v,it,src,vis);
            if(res)
                return true;
        }
        else if(parent!=it)
        {
            return true;
        }
    }
    
    return false;
}
bool checkCycle(vector<int> adj[],int V)
{
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++)
    {
        // for disconnected components:
        if(vis[i]==false)
        {
            if(dfs(adj,V,i,-1,vis))
                return true;
        }
    }
    return false;
}
int main()
{
    int V,e;
    cin>>V>>e;
    vector<int> adj[V];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    checkCycle(adj,V);
    return 0;
}