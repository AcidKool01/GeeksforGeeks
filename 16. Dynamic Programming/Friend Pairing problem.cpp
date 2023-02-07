#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    int mod = 1000000007;

    long long int solve (int n, vector<int> &dp)
    {
        if(n==1 || n==2)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
            
        long long int x = solve(n-1, dp)%mod;
        long long int y = ((n-1)%mod*solve(n-2, dp)%mod)%mod;
        
        return dp[n] = (x%mod+y%mod)%mod;
    }

    int countFriendsPairings(int n) 
    { 
        vector<int> dp (n+1, -1);
        return solve(n, dp);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
}