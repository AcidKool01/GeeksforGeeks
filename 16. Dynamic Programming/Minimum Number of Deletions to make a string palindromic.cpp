#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int solve (string &a, string &b, int n, int m, vector<vector<int>> &dp)
{
    if (n==0 || m==0)
        return 0;
    
    if (dp[n][m] != -1)
        return dp[n][m];
        
    if (a[n-1] == b[m-1])
        return dp[n][m] = 1 + solve (a, b, n-1, m-1, dp);
    
    else
        return dp[n][m] = max (solve(a, b, n-1, m, dp), solve(a, b, n, m-1, dp));
}

int minDeletions(string a, int n) { 
    
    string b = "";
    
    for (int i = n-1; i>=0; i--)
        b+=a[i];
  
    int m = b.size();
    
    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
    
    solve (a, b, n, m, dp);
    
    return n - dp[n][m];
}