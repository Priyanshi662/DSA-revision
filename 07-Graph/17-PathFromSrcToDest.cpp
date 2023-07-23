#include <vector>
using namespace std;
// https://leetcode.com/problems/all-paths-from-source-to-target/description/
class Solution {
public:
   void dfs(vector<vector<int>> &g,vector<vector<int>> &ans,vector<int> temp,int src,int dest)
   {
       temp.push_back(src);
       if(src==dest)
       {
           ans.push_back(temp);
           return;
       }
       else
       {
           for(auto it: g[src])
           {
               dfs(g,ans,temp,it,dest);
           }
       }
       temp.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<vector<int>> ans;
       vector<int> temp;
       dfs(graph,ans,temp,0,n-1);
       return ans;
    }
};