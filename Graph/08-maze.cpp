#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &maze ,int x,int y,int dx,int dy)
{
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    queue<pair<int,int>> q;
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    q.push(make_pair(x,y));
    vis[x][y]=true;
    while(!q.empty())
    {
        auto p=q.front();
        if(p.first ==dx && p.second==dy)
            return true;
        for(int i=0;i<4;i++)
        {
            int nx=p.first+row[i];
            int ny=p.second+col[i];
            // move in that direction until it hits another wall
            while(nx>=0 && nx <n && ny>=0 && ny<n && maze[nx][ny]==0)
            {
                nx+=row[i];
                ny+=col[i];
            }
            if(vis[nx-row[i]][ny-col[i]]==false)
            {
                q.push(make_pair(nx-row[i],ny-col[i]));
                vis[nx-row[i]][ny-col[i]]=true;
            }
        }
    }
    return false;
}
bool dfs(vector<vector<int>>& maze,int x,int y,int dx,int dy,vector<vector<bool>> &vis)
{
    if(vis[x][y]==true)
        return false;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int n=maze.size();
    int m=maze[0].size();
    vis[x][y]=true;
    if(x<0 || x>= n || y<0 || y>=m || maze[x][y]==1)
        return false;
    if(x==dx && y==dy)
        return true;
    
    for(int i=0;i<4;i++)
    {
        int nx=x+row[i];
        int ny=y+col[i];
        while(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]==0)
        {
            nx=nx+row[i];
            ny=ny+col[i];
        }
        // while loop stops where the ball hits the wall
        if(vis[nx-row[i]][ny-col[i]]==false)
        {
            return dfs(maze,nx-row[i],ny-col[i],dx,dy,vis);
        }
    }
    return false;
}
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    return dfs(maze,start[0],start[1],destination[0],destination[1],vis);
}