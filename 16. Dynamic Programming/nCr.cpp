#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Here idea is to use property of ncr...

//  n       n-1                 n-1
//   C =        C        +          C
//    r           r-1                  r

class Solution{
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        
        if (r > n - r)
            r = n - r;
            
        int mod = 1000000007;
        
        vector<vector<int>> dp(n+1, vector<int>(r+1, 0));
        for(int i=1; i<n+1; i++)
        {
            for (int j=0; j<r+1; j++)
            {
                if(j == 0 || i == j)
                {
                    dp[i][j] = 1;
                }
                
                else
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }
        
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