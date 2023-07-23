// C++ Program to find minimum edge reversal to get
// atleast one path from source to destination
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V;
	list<pair<int, int>> *graph;

public:
	// Constructor:
	Graph(int V)
	{
		this->V = V;
		graph = new list<pair<int, int>>[V];
	}

	// Adding edges into the graph:
	void addEdge(int u, int v, int w)
	{
		graph[u].push_back(make_pair(v, w));
	}

	// Returns shortest path from source to all other vertices.
	vector<int> shortestPath(int source)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,source});
		vector<int> dist(V,INT_MAX);
		dist[source]=0;
		while(pq.size()>0)
		{
		    auto curr=pq.top();
		    
		    int u=curr.second;
		    int d=curr.first;
		    
		    for(auto it: graph[u])
		    {
		        int v=it.first;
		        int w=it.second;
		        if(w+dist[u] < dist[v])
		        dist[v]=w+dist[u];
		        pq.push({dist[v],v});
		    }
		}
		return dist;
	}

	Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
	{
		Graph g(V);
		for(int i=0;i<V;i++)
		{
		    int u=edge[i][0];
		    int v=edge[i][1];
		    g.addEdge(u,v,0);
		    g.addEdge(v,u,1);
		}
		return g;
	}

	int getMinEdgeReversal(int edge[][2], int E, int V, int source, int destination)
	{
		// get modified graph with edge weight.
		Graph g = modelGraphWithEdgeWeight(edge, E, V);

		// distance vector stores shortest path.
		vector<int> dist = g.shortestPath(source);

		// If distance of destination is still INF then we cannot reach destination. Hence, not possible.
		if (dist[destination] == INF)
			return -1;
		else
			return dist[destination];
	}
};
