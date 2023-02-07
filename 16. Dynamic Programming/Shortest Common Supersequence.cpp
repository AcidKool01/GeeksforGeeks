#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    int solve (int x, int y, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(x==0 || y==0)
            return 0;
            
        if(dp[x][y] != -1)
            return dp[x][y];
        
        if (s1[x-1]==s2[y-1])
            return dp[x][y] = 1 + solve (x-1, y-1, s1, s2, dp);
        
        else
            return dp[x][y] = max(solve(x-1, y, s1, s2, dp), solve(x, y-1, s1, s2, dp));
    }
    
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
        int lcs = solve (n, m, X, Y, dp);
        
        return n+m-lcs;
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}