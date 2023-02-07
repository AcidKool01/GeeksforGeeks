#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfs (int V, vector<int> adj[], vector<bool> &visited, vector<int> &low, vector<bool> &isAP, vector<int> &discTime, int &t, int &p) {
        
        int children = 0;
        visited[V] = true;
        
        discTime[V] = low[V] = t;
        t++;
        
        for (auto x: adj[V]) {
            if(!visited[x]) {
                children++;
                dfs(x, adj, visited, low, isAP, discTime, t, x);
                
                low[V] = min(low[V], low[x]);
                
                if(p!=-1 && low[x]>=discTime[V]) {
                    isAP[V] = 1;
                }
            }
            
            else if(x!=p) {
                low[V] = min(low[V], discTime[x]);
            }
        }
        
        if(p==-1 && children>1) {
            isAP[V] = 1;
        }
        
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> visited(V, false);
        vector<int> low(V, 0);
        vector<bool> isAP(V, false);
        vector<int> discTime (V, 0);
        vector<int> ans;
        
        int t=0, p=-1;
        
        for (int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, low, isAP, discTime, t, p);
            }
        }
        
        for (int i=0; i<V; i++) {
            if(isAP[i]==1) {
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0) {
            ans.push_back(-1);
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}