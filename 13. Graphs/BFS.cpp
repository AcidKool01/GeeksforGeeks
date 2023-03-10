// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int v, vector<int> adj[])
	{
            int src = 0;
            vector<int> ans;
        
            queue<int> q;
            bool visited[v] = {0};
        
            q.push(src);
            visited[src] = 1;
        
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                ans.push_back(t);
        
                for(auto x: adj[t])
                {
                    if(visited[x]==0)
                        q.push(x);
                    visited[x] = 1;
                }
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

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends