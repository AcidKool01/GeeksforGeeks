#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    // int solve (int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    // {
    //     if(n==0 || W==0)
    //         return 0;
            
    //     if(dp[n][W]>-1)
    //         return dp[n][W];
        
    //     if(wt[n-1]<=W)
    //     {
    //         return dp[n][W] =  max(val[n-1]+solve(W-wt[n-1], wt, val, n-1, dp), solve(W, wt, val, n-1, dp));
    //     }
        
    //     else if(wt[n-1]>W)
    //     {
    //         return dp[n][W] =  solve(W, wt ,val, n-1, dp);
    //     }
        
    //     return dp[n][W];
    // }

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[n+1][W+1];
        
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        
        for(int j = 0; j <= W; j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                if(wt[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]] ,dp[i-1][j]);
                }
            }
        }
        
        return dp[n][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}