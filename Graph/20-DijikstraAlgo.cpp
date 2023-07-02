#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> dijikstra(vector<vector<int>> adj[],int n)
{
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<bool> vis(n,false);
    vis[0]=true;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        for(auto it: adj[p.second])
        {
            int v=it[0];
            int wt=it[1];
            if(wt+dist[p.first]<dist[v])
            {
                dist[v]=wt+dist[p.first];
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}


// Implementation of Dijikstra 
// https://leetcode.com/problems/path-with-maximum-probability/description/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }   
        vector<double> dist(n,INT_MIN);
        vector<bool> visited(n,false);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        visited[start]=true;
        dist[start]=1;
        // probabilities multiplies when moving from source to destination
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            for(auto it:adj[p.second])
            {
                int v=it.first;
                double wt=it.second*dist[p.second];
                if(wt>dist[v])
                {
                    dist[v]=wt;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[end]==INT_MIN)
            return 0.00000;
        else return dist[end];
    }
};
// for furthur practice :
// https://leetcode.com/problems/network-delay-time/description/