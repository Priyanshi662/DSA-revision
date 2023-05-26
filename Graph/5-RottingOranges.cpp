#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
// time complexity :O(mn) SC: O(mn)
    int orangesRotting_usingBFS(vector<vector<int>>& A) {
        queue<pair<int, int>> q;
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 2) q.emplace(i, j);
            }
        }
        while (q.size()) {
            for (int cnt = q.size(); cnt--;) {
                auto [x, y] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] != 1) continue;
                    A[a][b] = 2;
                    q.emplace(a, b);
                }
            }
            step++;
        }
        for (auto &row : A) {
            for (int x : row) {
                if (x == 1) return -1;
            }
        }
        return max(0, step - 1);
    }
    // using dfs:
    void solve(vector<vector<int>>& grid,int x,int y,int mins)
    {
        if(x<0|| x>=grid.size() || y<0 || y>=grid[0].size())
            return;
        if(grid[x][y]==0)
            return;
        if(grid[x][y]>=2 && grid[x][y]<mins)
            return;
        grid[x][y]=mins;
        solve(grid,x+1,y,mins+1);
        solve(grid,x,y+1,mins+1);
        solve(grid,x-1,y,mins+1);
        solve(grid,x,y-1,mins+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    solve(grid,i,j,2);
                    // minutes are passed as 2 to prevent writing value as 0 or 1 because they are reserved
            }
        }
        int ans=2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
                else
            ans=max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};