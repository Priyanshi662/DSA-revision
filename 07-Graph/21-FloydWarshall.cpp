#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FloydWarshall(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    dist[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            int src=adj[i][0];
            int dst=adj[i][1];
            int wt =adj[i][2];
            dist[src][dst]=wt;
            dist[dst][src]=wt;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][i]));
                }
            }   
        }
    }
};