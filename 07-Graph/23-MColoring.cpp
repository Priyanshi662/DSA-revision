#include <vector>
#include <iostream>

using namespace std;

bool isSafe(vector<vector<int>> &adj,vector<int> &color,int u,int curr_color)
{
    for(int i=0;i<adj.size();i++)
    {
        if(i!=u && adj[u][i]>0 && color[i]==curr_color)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&adj,int m,int u ,vector<int> color)
{
    if(u==adj.size())
        return true;
    for(int i=1;i<m;i++)
    {
        if(isSafe(adj,color,u,i))
        {
            color[u]=i;
            if(solve(adj,m,u+1,color))
                return true;
            // try for another combination from next node
            color[u]=0;
        }
    }
    return false;
}
bool graphcolor(vector<vector<int>> &adj,int N,int m)
{
    vector<int> color(N,-1);
    bool res=false;
    res=solve(adj,m,0,color);
    return res;
}