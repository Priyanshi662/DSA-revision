// https://leetcode.ca/2017-10-24-694-Number-of-Distinct-Islands/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
    public:
        void exploreDFS(vector<vector<int>> &grid,string &path,int x,int y,char ch)
        {
            if(x<0 ||  x>=grid.size() ||  y<0 || y>=grid[0].size() || grid[x][y]==0)
                return;
            // mark this as visited :
            grid[x][y]=0;
            path+=ch;
            exploreDFS(grid,path,x,y+1,'d');
            exploreDFS(grid,path,x+1,y,'r');
            exploreDFS(grid,path,x,y-1,'u');
            exploreDFS(grid,path,x-1,y,'l');
            path.push_back('x');
        }
        int numDistinctIslands(vector<vector<int>>& grid) {
            unordered_set<string> st;
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1)
                    {    string path;
                        exploreDFS(grid,path,i,j,'o');
                        if(path.size())
                            st.insert(path);
                    }
                }
            }
            return st.size();
        }
};
int main()
{
    Solution ob;
    vector<vector<int>> grid={{1,1,0,0,1,1,1},
                              {1,0,0,0,0,0,0},
                              {0,0,1,1,0,0,0},
                              {1,1,0,0,0,0,0}};
    int ans=ob.numDistinctIslands(grid);
    std::cout<<ans;
    return 0;
}