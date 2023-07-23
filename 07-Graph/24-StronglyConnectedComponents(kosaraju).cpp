#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsStack(vector<vector<int>> &adj,vector<int> vis,int curr,stack<int> &st)
{
    if(vis[curr])
        return;
    vis[curr]=true;
    for(auto it:adj[curr])
    {
        if(vis[it]==false)
            dfsStack(adj,vis,it,st);
    }
    // after every dfs add the parent node
    st.push(curr);
}
void dfs(vector<vector<int>> &adj,vector<int> &vis,int curr,vector<int> &temp)
{
    if(vis[curr])
        return ;
    vis[curr]=true;
    temp.push_back(curr);
    for(auto it: adj[curr])
    {
        if(vis[it]==false)
        {
            dfs(adj,vis,it,temp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> vis(n,false);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
            dfsStack(adj,vis,i,st);
    }
    vector<vector<int>> copyadj;
    for(int i=0;i<n;i++)
    {
        int u=i;
        for(auto it: adj[u])
            copyadj[it].push_back(u);
    }
    fill(vis.begin(),vis.end(),false);
    int ans=0;
    vector<vector<int>> res;
    while(!st.empty())
    {
        int i=st.top();
        st.pop();
        if(vis[i]==false)
        {
            vector<int> temp;
            dfs(copyadj,vis,i,temp);
            res.push_back(temp);
            ans++;
        }
    }   
    return res;
}