#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  long long int x=0, y=0, z=0;
  
  long long int solve (int M, int N, int X, vector<vector<long long int>> &dp) {
        if(N==0 && X==0) 
            return 1;

        if(X<=0 || N==0) 
            return 0;
            
        if(dp[N][X] != -1)
            return dp[N][X];
            
        long long int ans = 0;
      
        for (int i=1; i<=M; i++) {
            ans+=solve(M, N-1, X-i, dp);
        }
        
        return dp[N][X] = ans;
  }
  
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long int>> dp(N+1, vector<long long int> (X+1, -1));
        solve(M, N, X, dp);
        
        return dp[N][X];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
} 