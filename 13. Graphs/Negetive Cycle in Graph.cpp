#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    vector<int> dist(V, INT_MAX);
        
        dist[0] = 0;
        
        for(int i = 0; i < V-1; i++)
        {
            
            for (auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                
                if(dist[edge[0]] != INT_MAX && dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                }
            }
            
        }
        
        for(auto x:edges)
	        if(dist[x[0]]!=INT_MAX and dist[x[1]]>dist[x[0]]+x[2])
	            return 1;
	            
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
} 