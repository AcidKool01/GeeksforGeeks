#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    	bool isPossible(int N, vector<pair<int, int> >& edges) {
	    
	    vector<int>adj[N+1];
	    for(int i=0;i<edges.size();i++)
	    {
	        int n1=edges[i].first;
	        int n2=edges[i].second;
	        adj[n2].push_back(n1);
	    }
	    
	    vector<int>indeg(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto j:adj[i])
	        {
	            indeg[j]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<indeg.size();i++)
	    {
	        if(indeg[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    int count=0;
	    while(!q.empty())
	    {
	        int num=q.front();
	        count++;
	        q.pop();
	        for(int m:adj[num])
	        {
	            indeg[m]--;
	            if(indeg[m]==0)
	            {
	                q.push(m);
	            }
	        }
	    }
	    
	    if(count==N)
	    {
	        return true;
	    }
	    
	    else
	    {
	        return false;
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
} 