#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    void bfs(vector<vector<int>> &img,int x,int y,int color)
    {
        if(img[x][y]== color)
            return;

        queue<pair<int,int>> q;
        q.push(make_pair(x,y));

        int inicolor=img[x][y];

        int row[4]={0,1,0,-1};
        int col[4]={1,0,-1,0};

        int m=img.size();
        int n=img[0].size();

        img[x][y]=color;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            x=p.first;
            y=p.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+row[i];
                int ny=y+col[i];
                if(nx < 0 || nx >=m || ny<0 || ny>=n || img[nx][ny]!=inicolor)
                   continue;

                img[nx][ny]=color;
                q.push(make_pair(nx,ny));
            }   
        }
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image,sr,sc,color);
        return image;
    }
};