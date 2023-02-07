// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    bool DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[])
    {
        visited[s] = true;
        recSt[s] = true;
        
        for(int u: adj[s])
        {
            if(visited[u] == false)
            {
                if(DFSRec(adj, u, visited, recSt) == true)
                {
                    return true;
                }
            }
            else if(recSt[u] == true)
            {
                return true;
            }
        }
        
        recSt[s] = false;
        return false;
    }
    
    public:
    bool isCyclic(int V, vector<int> adj[]) 
    {
        bool visited[V+1] = {0}, recSt[V+1] = {0};
    
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == false)
            {
                if(DFSRec(adj, i, visited, recSt) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends