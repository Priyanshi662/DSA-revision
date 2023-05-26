#include <iostream>
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<int> adj[],int V,vector<int> ans,vector<bool> vis,int x)
{
    if(vis[x])
        return ;
    vis[x]=true;
    ans.push_back(x);
    for(auto it: adj[x])
    {
        dfs(adj,V,ans,vis,it);
    }
    return ;
}
vector<int> solve(vector<int>adj[],int V)
{
    vector<int> ans;
    vector<bool> vis(V,false);
    dfs(adj,V,ans,vis,0);
    return ans;
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
        adj[v].push_back(u);
    }
    vector<int> dfs=solve(adj,V);
    for(int i=0;i<V;i++)
    {
        cout<<dfs[i]<<" ";
    }
    return 0;
}