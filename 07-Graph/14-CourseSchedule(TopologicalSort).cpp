#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// This can be done by two algorithms - Kahns and Tarjan Algo
class Solution {
public:
    typedef vector<vector<int>> vvi;
    
    void buildgraph(vvi &adj,vvi & pre,vector<int> &ind)
    {
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
    }
    bool canFinish(int n, vvi & pre) {
        if(n==0)
            return true;
        vvi adj(n,vector<int>());
        vector<int> indegree(n);
        buildgraph(adj,pre,indegree);
        queue<int>  q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int nx=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            nx++;
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return nx==n;
    }
    bool canFinish2(vvi &pre,int n)
    {
        
    }
};