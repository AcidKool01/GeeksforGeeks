#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve (int n, int m, int a[], vector<vector<bool>> &dp)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                if(j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;   
                else if(j < a[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
        return dp[n][m];
    }

    int equalPartition(int n, int arr[])
    {   
        int m = 0;
        for(int i=0; i<n; i++)
            m+=arr[i];
        
        if(m%2!=0)
            return 0;
        
        vector<vector<bool>> dp (n+1, vector<bool>(m+1, 0));
        
        return solve(n, m/2, arr, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}