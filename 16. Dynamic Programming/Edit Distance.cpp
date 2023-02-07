#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    int solve (string s, string t, int n, int m, vector<vector<int>> &dp)
    {
        if (n==0)
            return m;
        
        if (m==0)
            return n;
            
        if (dp[n][m] != -1)
            return dp[n][m];
            
        if (s[n-1]==t[m-1])
            return dp[n][m] = solve(s, t, n-1, m-1, dp);
        
        else
            return dp[n][m] = 1 + min ({solve(s, t, n-1, m-1, dp), solve(s, t, n-1, m, dp), solve(s, t, n, m-1, dp)});
    }
  
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1));
        solve (s, t, n, m, dp);
        
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}