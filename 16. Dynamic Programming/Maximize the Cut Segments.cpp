#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int util(int n, int x, int y, int z, vector<int> &dp)
    {
        if(n==0)
        {
            return dp[n] = 0;
        }
        
        if (n<x && n<y && n<z)
            return dp[n] = INT_MIN;
        
        if(dp[n]!=-1)
            return dp[n];
            
        int a = n>=x ? 1 + util(n-x, x, y, z, dp) : INT_MIN;
        int b = n>=y ? 1 + util(n-y, x, y, z, dp) : INT_MIN;
        int c = n>=z ? 1 + util(n-z, x, y, z, dp) : INT_MIN;
  
        return dp[n] = max({a, b, c});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1, -1);
        
        int res = util(n, x, y, z, dp);
        
        return res>0 ? res : 0;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}