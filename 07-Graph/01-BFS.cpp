#include <iostream>
#include <unordered_map> 
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(vector<int>adj[],int V)
{
    vector<int> bfs;
    vector<bool> visited(V,false);
    queue<int> q;
    bfs.push_back(0);
    visited[0]=true;
    q.push(0);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto it: adj[v])
        {
            if(visited[it]!=true)
            {
                bfs.push_back(it);
                q.push(it);
                visited[it]=true;
            }
            else
            {
                continue;
            }
        }
    }
    return bfs;
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
    vector<int> bfs=solve(adj,V);
    for(int i=0;i<V;i++)
    {
        cout<<bfs[i]<<" ";
    }
    return 0;
}