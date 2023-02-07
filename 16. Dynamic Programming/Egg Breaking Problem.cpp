#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve (int n, int f, vector<vector<int>> &dp)
    {
        if(f==0 || f==1)
            return f;
        
        if(n==1)
            return f;
            
        if (dp[n][f] != -1)
            return dp[n][f];
            
        int res = INT_MAX;
        
        for (int k=1; k<=f; k++)
        {
            int temp = 1 + max (solve(n-1, k-1, dp), solve(n, f-k, dp));
            res = min(res, temp);
        }
        return dp[n][f] = res;
    }
    
    int eggDrop(int n, int k) 
    {   
        vector<vector<int>> dp (n+1, vector<int> (k+1, -1));
        return solve (n, k, dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}