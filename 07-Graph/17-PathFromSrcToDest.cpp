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

// BFS Solution:
#include <queue>

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        
        queue<vector<int>> q;
        q.push({0}); // Starting with node 0
        
        while (!q.empty()) {
            vector<int> currentPath = q.front();
            q.pop();
            int currentNode = currentPath.back();
            
            if (currentNode == n - 1) {
                result.push_back(currentPath);
                continue;
            }
            
            for (int neighbor : graph[currentNode]) {
                vector<int> curr_path = currentPath;
                curr_path.push_back(neighbor);
                q.push(curr_path);
            }
        }
        
        return result;
    }
};
