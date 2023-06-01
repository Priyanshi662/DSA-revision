#include <iostream>
#include <vector>
using namespace std;


void solve(vector<vector<int>> grid,int x,int y,string temp,vector<string> &ans,vector<vector<bool>> &vis,int n)
{
    if(x<0 || x>=n || y<0 ||y>=n || grid[x][y]==0 || vis[x][y]==true)
        return;
    if(x==n-1 && y==n-1)
    {
        ans.push_back(temp);
        return;
    }
    
    int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
    char dirch[4]={'U','D','L','R'};
    for(int i=0;i<4;i++)
    {
        vis[x][y]=true;
        solve(grid,x+dir[i][0],y+dir[i][1],temp+dirch[i],ans,vis,n);
        vis[x][y]=false;
    }
}
vector<string> searchInTheMaze(vector<vector<int>> &grid,int n)
{
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<string> ans;
    int sr=0,sc=0;
    string s="";
    solve(grid,sr,sc,s,ans,visited,n);
    return ans;
}   