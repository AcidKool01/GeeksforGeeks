#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    
    int solve (int a, int b, vector<vector<int>> &dp)
    {
        if(a==1 && b==1)
            return 1;
        
        if(dp[a][b] >-1)
            return dp[a][b];
            
        int x=0, y=0;
        
        if(a!=1)
            x = solve(a-1, b, dp);
        
        if(b!=1)
            y = solve(a, b-1, dp);
        
        return dp[a][b] = x+y;
    }
    
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp (a+1, vector<int> (b+1, -1));
        dp[1][1] = 1;
        
        return solve(a, b, dp);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}