#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution {
public:
    void dfsCount(vector<vector<int>> &g,vector<bool> &vis,int u)
    {
        vis[u]=true;
        for(auto it:g[u])
        {
            if(!vis[it])
                dfsCount(g,vis,it);
        }
    }
    // by dfs: (naive approach)
    int makeConnected(int n, vector<vector<int>>& c) 
    {
        // find number of disconnected components
        // should be equal to n-1
        int m=c.size();
        if(m<n-1)
            return -1;
        vector<vector<int>> g(n);
        for(auto v: c)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n,false);
         int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfsCount(g,visited,i);
                count++;
            }
        }
        return count-1;
    }
    // By union find :
    int find(int node,vector<int> &parent)
    {
        if(node==parent[node])
            return node;
        else
            return parent[node]=find(parent[node],parent);
    }
    int makeConnected2(int n,vector<vector<int>> & c)
    {
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int rededge=0;
        for(int i=0;i<c.size();i++)
        {
            int u=c[i][0];
            int v=c[i][1];
            int p1=find(u,parent);
            int p2=find(v,parent);
            if(p1==p2)
                rededge++;
            else
            {
                parent[p1]=p2;
            }
        }
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                cc++;
        }
        int ans=cc-1;
        if(ans <=rededge)
            return ans;
        else    
            return -1;
    }
};
