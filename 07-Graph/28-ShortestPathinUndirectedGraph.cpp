#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;
class Solution {
public:
    vector<int> shortestPath(vector<int> adj[],int src,int dest)
    {
        unordered_map<int,vector<int>> mp;
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty())
        {
            int currnode=q.front().first;
            int h=q.front().second;
            if(currnode==dest)
            {    
                mp[h].push_back(currnode);
                break;
            }
            for(auto it:adj[src])
            {
                q.push({it,h+1});
            }
        }
        int mindist=INT_MAX;
        for(auto it: mp)
        {
            if(it.first<mindist)
            {
                mindist=it.first;
            }
        }
        for(auto it: mp)
        {
            if(it.first==mindist)
            {
                return it.second;
            }
        }
    }
};