// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	// Function to detect cycle in an undirected graph.
	bool isCyclic_Util(vector<int> adj[], vector<int> visited, int curr)
	{
		if (visited[curr] == 2)
			return true;

		visited[curr] = 1;
		bool flag = false;

		for (int i = 0; i < adj[curr].size(); ++i)
		{
			if (visited[adj[curr][i]] == 1)
				visited[adj[curr][i]] = 2;
			else
			{
				flag = isCyclic_Util(adj, visited, adj[curr][i]);
				if (flag == true)
					return true;
			}
		}
		return false;
	}

	bool isCycle(int V, vector<int> adj[])
	{
		// code here
		vector<int> visited(V, 0);
		bool flag = false;

		for (int i = 0; i < V; ++i)
		{
			visited[i] = 1;
			for (int j = 0; j < adj[i].size(); ++j)
			{
				flag = isCyclic_Util(adj, visited, adj[i][j]);
				if (flag == true)
					return true;
			}
			visited[i] = 0;
		}
		return false;
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
} // } Driver Code Ends