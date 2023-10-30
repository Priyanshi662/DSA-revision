#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// we need to use backtracking because their will be forward edges in a loop and backward edges to bring it back to a single point
// Check for back edges which lead upto the ancestor node of the current node
// Cannot use method which uses parent vector because here path is not two way
// so checking parent and visited is not enough
// we need to check if the control keeps repeating the same nodes or not(constitutes a loop)
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
            return true;
        }
    }
    dfsvis[src]=false;
    return false;
}
bool checkCycle(vector<int> adj[],int V)
{
    vector<bool> vis(V,false);
    vector<bool> dfsvisit(V,false);
    for(int i=0;i<V;i++)
    {
        // for disconnected components:
        if(vis[i]==false)
        {
            if(dfs(adj,V,i,dfsvisit,vis))
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