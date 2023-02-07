#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minCost(int N, vector<int> cost[]) {
        vector<vector<int>> dp (N+1, vector<int>(3, -1));
        int res = 0;
        
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        
        for (int i=1; i<N+1; i++)
        {
            dp[i][0] = cost[i-1][0] + min(dp[i-1][1], dp[i-1][2]); 
            dp[i][1] = cost[i-1][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = cost[i-1][2] + min(dp[i-1][0], dp[i-1][1]);
            
            res = min(dp[i][0], min (dp[i][1], dp[i][2]));
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        Solution ob;
        cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
} 