// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int u, vector<bool> &vis, vector<int> adj[])
    {
        vis[u] = 1;
        
        for(auto v : adj[u])
        {   
            if(vis[v]==0)
                dfs(v, vis, adj);
        }
    }
  
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V, 0);
	    int ans = -1;
	    
	    for (int i=0; i<V; i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i, vis, adj);
	            ans = i;
	        }
	    }
	    
	    vector<bool> visit (V, 0);
	    
	    dfs(ans, visit, adj);
	    
	    for (int i=0; i<V; i++)
	    {
	        if(visit[i]==0)
	            return -1;
	    }
	    
	    return ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends