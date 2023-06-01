#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// For logic understanding - https://cp-algorithms.com/graph/bipartite-check.html#algorithm
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool isbipartite=true;
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                q.push(i);
                while(q.size())
                {
                    int v=q.front();
                    q.pop();
                    for(auto it:graph[v])
                    {
                        if(color[it]==-1)
                        {
                            color[it]=color[v]^1;
                            q.push(it);
                        }
                        else
                        {
                            isbipartite=isbipartite&&(color[it]!=color[v]);
                            if(!isbipartite)
                                return false;
                        }
                    }
                }
            }
        }
        return isbipartite;
    }
};