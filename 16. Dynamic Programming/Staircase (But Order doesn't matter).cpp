#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.//

    //Lets say that jump =1, so for any stair, the number of ways will always be equal to 1.

    // Now for jump=2, say for stair 8: no of ways will be 
    //(no of ways to reach 8 using 1 only)+(no of ways to reach 6 using both 1 and 2 because you can reach to 8 from 6 by just a jump of 2).
    long long countWays(int m)
    {
        vector<long long int> dp (m+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= m; i++)
        {
            dp[i] = (dp[1] + dp[i-2])%1000000007;
        }
        
        return dp[m];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
} 