#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& maze,int x,int y,int dx,int dy,char dir)
{
    bool changedir=false;
    if(dir=='l' && maze[x-1][y]==1)
    {
        changedir=true;
    }
    
}
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

}