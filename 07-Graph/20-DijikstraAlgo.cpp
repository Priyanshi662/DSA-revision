#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> dijikstra(vector<vector<int>> adj[],int n)
{
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<bool> vis(n,false);
    vis[0]=true;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        for(auto it: adj[p.second])
        {
            int v=it[0];
            int wt=it[1];
            if(wt+dist[p.first]<dist[v])
            {
                dist[v]=wt+dist[p.first];
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}


// Implementation of Dijikstra 
// https://leetcode.com/problems/path-with-maximum-probability/description/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }   
        vector<double> dist(n,INT_MIN);
        vector<bool> visited(n,false);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        visited[start]=true;
        dist[start]=1;
        // probabilities multiplies when moving from source to destination
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            for(auto it:adj[p.second])
            {
                int v=it.first;
                double wt=it.second*dist[p.second];
                if(wt>dist[v])
                {
                    dist[v]=wt;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[end]==INT_MIN)
            return 0.00000;
        else return dist[end];
    }
};
// for furthur practice :
// https://leetcode.com/problems/network-delay-time/description/



#include <iostream>
using namespace std;
#include <limits.h>
 
#define V 6 // Number of vertices in the graph
 
//Function to find the vertex with minimum distance
int minDist(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
//Function to print the constructed distance array
void printSolution(int distance[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << (char)(i+65) << " \t\t"<<distance[i]<< endl;
}
 
// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; //inititalizing output array
 
    bool sptSet[V]; // list of visisted nodes
    
    // Initializing all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Setting distance of source as 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        
        //calling minDistance to pick next vertex
        int u = minDist(dist, sptSet);
 
        // Mark the picked vertex as visited
        sptSet[u] = true;
 
        //Relaxing all neighbours of U
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}
// driver function
int main()
{
   
    //Example graph
    //Same as Graph in example diagram above
    
    int graph[V][V] = { {0,4,5,0,0,0},
                        {4,0,11,9,7,0},
                        {5,11,0,0,3,0},
                        {0,9,0,0,13,2},
                        {0,7,3,13,0,6},
                        {0,0,0,2,6,0}};
     int source=0;
    dijkstra(graph, source);
 
    return 0;
}