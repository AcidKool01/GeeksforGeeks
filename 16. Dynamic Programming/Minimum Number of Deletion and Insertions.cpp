#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
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
	
	int minOperations(string a, string b) 
	{ 
	    int n = a.size();
	    int m = b.size();
	    
	    vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
	    
	    solve(a, b, n, m, dp);
	    
	    return ((n-dp[n][m]) + (m-dp[n][m]));
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}