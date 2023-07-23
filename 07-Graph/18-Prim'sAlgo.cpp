#include <bits/stdc++.h>
using namespace std;

int minimumSpanningTree(vector<vector<int>> adj[],int n)
{
    // number of vertices with directed acyclic weighted graph
    unordered_map<int,vector<pair<int,int>>> mp;
    // int -> parent node
    // pii -> children with weight
    for(int i=0;i<n;i++)
    {
        vector<pair<int,int>> t;
        for(auto it:adj[i])
        {
            int v=it[0];
            int wt=it[1];
            t.push_back({v,wt});
        }
        mp[i]=t;
    }
    vector<int> wt(n,INT_MAX);
    vector<int> parent(n,-1);
    vector<bool> vis(n,false);
    // outer loop is to ensure n-1 edges are picked
    for(int i=0;i<n-1;i++)
    {
        int minwt=INT_MAX;
        int u;
        // this loop can be converted to minHeap
        for(int j=0;j<n;j++)
        {
            if(vis[j] ==false && wt[j]<minwt)
            {
                minwt=wt[j];
                // choosing the minimum vertex
                u=j;
            }
        }
        vis[u]=true;
        // traverse the children and find the minimum weight edge
        for(auto it: adj[u])
        {
            int v=it[0];
            int currwt=it[1];
            if(vis[v]==false && currwt<wt[v])
            {
                wt[v]=currwt;
                parent[v]=u;
            }
        }
    }
    int minCost=0;
    // wt array will contain minimum weights of every chosen edge
    for(int i=0;i<n;i++)
    {
        if(wt[i]!=INT_MAX)
            minCost+=wt[i];
    }   
    return minCost;
}

// Implementation -1584. Min Cost to Connect All Points
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int minCost=0;
        int u=0;
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>> pq;
        int i=1;
        for(;i<n;i++)
        {
            vis[u]=true;
            for(int v=0;v<n;v++)
            {
                if(vis[v]==false)
                {
                    int x=abs(points[u][0]-points[v][0]);
                    int y=abs(points[u][1]-points[v][1]);
                    int tot=x+y;
                    pq.push({-tot,v});
                }
            }
            while(vis[pq.top().second])
                pq.pop();
            // minimum cost not traversed edge found
            minCost-=pq.top().first;
            u=pq.top().second;
            pq.pop();
        }
        return minCost;
    }
};