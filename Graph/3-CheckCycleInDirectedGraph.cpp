#include <iostream>
#include <vector>
using namespace std;

// we need to use backtracking because their will be forward edges in a loop and backward edges to bring it back to a single point
// cannot use bfs because path is required to be checked
// Check for back edges which lead upto the ancestor node of the current node

bool dfs(vector<int> adj[],int v,int src,vector<bool> &dfsvis,vector<bool> &vis)
{
    dfsvis[src]=true;
    vis[src]=true;
    for(auto it: adj[src])
    {
        if(!vis[it])
        {
            bool res=dfs(adj,v,it,dfsvis,vis);
            if(res)
                return true;
        }
        else if(dfsvis[it])
        {
            // dfsvis[i] is true when this particular node has been visited in the current DFS iteration
            return true;
        }
    }
    dfsvis[src]=false;
    return false;
}
bool checkCycle(vector<int> adj[],int V)
{
    vector<bool> dfsvis(V,false);
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(adj,V,i,dfsvis,vis))
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