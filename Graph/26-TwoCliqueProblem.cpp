// Two clique problem - check whether the graph can be divided to two cliques or not
// clique is a subgraph which is strongly connected component
// now if we want to find two cliques in a graph we'll have to check various possibilities
// which will use big time complexity as well as be complicated.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
        bool isbipartite=true;
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                q.push(i);
                while(q.size())
                {
                    int v=q.front();
                    q.pop();
                    for(int it=0;it<n;it++)
                    {
                        if(graph[v][it]==1)
                        {
                            if(color[it]==-1)
                            {
                                color[it]=color[v]^1;
                                q.push(it);
                            }
                            else
                            {
                                isbipartite=isbipartite&&(color[it]!=color[v]);
                                if(!isbipartite)
                                    return false;
                            }
                        }
                    }
                }
            }
        }
    return isbipartite;
}
bool CanBeDivided(vector<vector<int>> &adj)
{
    vector<vector<int>> copy;
    int n=adj.size();
    // complement the graph
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
                copy[i][j]=(!adj[i][j]);
            else
                continue;
        }
    }
    // check if bipartite:
    if(isBipartite(adj))
        return true;
    else
        return false;
}