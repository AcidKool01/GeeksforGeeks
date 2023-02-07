#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    void dfs (int V, vector<int> adj[], vector<bool> &visited, vector<int> &low, vector<int> &discTime, int &t, int &p, bool &ans, int c, int d) {
        visited[V] = true;
        
        discTime[V] = low[V] = t;
        t++;
        
        for (auto x: adj[V]) {
            if(!visited[x]) {
                dfs(x, adj, visited, low, discTime, t, V, ans, c, d);
                
                low[V] = min(low[V], low[x]);
                
                if(low[x]>discTime[V]) {
                    if((x==c and V==d) || (x==d && V==c))
                        ans=1;
                }
            }
            
            else if(x!=p) {
                low[V] = min(low[V], discTime[x]);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        
        vector<bool> visited(V, false);
        vector<int> low(V, 0);
        vector<int> discTime (V, 0);
        bool ans=0;
        
        int t=0, p=-1;
        
        for (int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, low, discTime, t, p, ans, c, d);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}