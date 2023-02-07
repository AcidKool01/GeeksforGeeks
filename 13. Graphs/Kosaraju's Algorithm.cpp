#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfsTopological (int V, vector<int> adj[], stack<int> &st, vector<bool> &visited) {
  
	    visited[V]=true;
	    
	    for (auto x: adj[V]) {
	        if(!visited[x]) {
	            dfsTopological(x, adj, st, visited);
	        }
	    }
	    
	    st.push(V);
	}
	
	void dfs (int V, vector<int> adj[], vector<bool> &visited) {
	    
	    visited[V] = true;
	    for (auto x: adj[V]) {
	        if(!visited[x]) {
	            dfs(x, adj, visited);
	        }
	    }
	}
	
	void reverse (vector<int> adj[], vector<int> rev[], int V) {
	    for(int i=0; i<V; i++){
            for(auto j:adj[i]){
                rev[j].push_back(i);
            }
        }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {   
        stack<int> st;
        vector<bool> visited(V, 0);
        
        vector<bool> visitedRev(V, 0);
        vector<int> rev[V];
        int res=0;
        
        for (int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsTopological(i, adj, st, visited);
            }
        }
        
        reverse(adj, rev, V);
        
        while(!st.empty()) {
            int top = st.top();
            
            if(!visitedRev[top]) {
                res++;
                dfs(top, rev, visitedRev);
            }
            st.pop();
        }
        
        return res;
        
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends