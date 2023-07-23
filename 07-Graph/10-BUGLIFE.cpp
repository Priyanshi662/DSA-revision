// https://www.spoj.com/problems/BUGLIFE/
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph,int v)
{
    vector<int> color(v,-1);
    bool istrue=true;
    queue<int> q;
    for(int i=1;i<=v;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            q.push(i);
            while(q.size())
            {
                int x=q.front();
                q.pop();
                for(auto it:graph[i])
                {
                    if(color[it]==-1)
                    {
                        color[it]=color[x]^1;
                        q.push(it);
                    }
                    else
                    {
                        istrue&=(color[it]!=color[x]);
                        if(!istrue)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int t;
    std::cin>>t;
    for(int i=1;i<=t;i++)
    {
        int v,e;
        std::cin>>v>>e;
        vector<vector<int>> graph;
        for(int j=0;j<e;j++)
        {
            int x,y;
            std::cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if(isBipartite(graph,v))
        {
            std::cout<<"Scenario #"<<i<<":"<<endl;
            std::cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            std::cout<<"Scenario #"<<i<<":"<<endl;
            std::cout<<"No suspicious bugs found!"<<endl;
        }
    }
    return 0;
}