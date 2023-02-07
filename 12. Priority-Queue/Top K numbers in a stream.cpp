#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    struct cmp{
        bool operator() (pair<int,int> a,pair<int,int> b){
           if(a.second < b.second) return true;
           if(a.second == b.second)
             return (a.first > b.first);
           return false;
        }
    };
  
    vector<int> kTop(int arr[], int n, int k) 
    { 
        vector<int> res;
        priority_queue <pair<int, int>, vector<pair<int,int>>, cmp> q;
        map<int, int> mp;
        int count = 0;

     
        for (int i=0; i<n; i++) {
            // q.clear();
            mp.clear();
            count = 0;
            
            for (int j=0; j<=i; j++)
                mp[arr[j]]++;
            
            for (auto x: mp) {
                q.push({x.first, x.second});
            }
            
            while(!q.empty() && count<k) {
                res.push_back(q.top().first);
                q.pop();
                count++;
            }
            
            while(!q.empty())
            {
                q.pop();
            }
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}