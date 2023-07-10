#include <iostream>
#include <vector>
using namespace std;

int time=0;
void dfs(vector<vector<int>> &adj,vector<pair<int,int>> &res,vector<bool> &vis,vector<int> low,vector<int> disc,int curr,int parent)
{   
    disc[curr]=time;
    low[curr]=time;
    time++;
    for(auto it:adj[curr]){
        int v=it;
        // if it is parent it will not constitute bridge and will result in a cycle
        if(v==parent)
            continue;
        if(vis[v]==false)
        {
            parent=curr;
            dfs(adj,res,vis,low,disc,v,parent);
            low[curr]=min(low[curr],low[v]);
            if(low[v]>disc[curr])
            {   
                // then v cannot be reached by node other than curr(parent)
                res.push_back({curr,v});
            }
        }
        else
        {
            low[curr]=min(low[curr],disc[v]);
        }
    }
}

vector<pair<int,int>> tarjanAlgo(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> low(n,-1);
    vector<int> disc(n,-1);
    // if the nodes connected to the current node can be reached from other nodes too
    // i.e there disc time is greater than low then they do not constitute a bridge
    vector<pair<int,int>> res;
    vector<bool> vis(n,false);
    int parent=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            dfs(adj,res,vis,low,disc,i,parent);
        }
    }
    return res;
}