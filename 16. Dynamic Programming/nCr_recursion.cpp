// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int mod = 1000000007;

    int solve (int n, int r, vector<vector<int>> &dp)
    {   
        if(dp[n][r]>-1)
            return dp[n][r];
        
        if(r>n)
            return 0;
       
        if(n==r || r==0)
        {
            dp[n][r]=1;
            return dp[n][r];
        }
  
        dp[n][r] = (solve (n-1, r-1, dp) + solve(n-1, r, dp))%mod;
        
        return dp[n][r];
    }

    int nCr(int n, int r){
        if(r>n)
            return 0;
        
        if (r > n - r)
            r = n - r;
     
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));

        solve(n, r, dp);
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends