#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int solve (int arr[], int n, vector<int> &dp)
    {
        if(n<=0)
            return 0;
            
        if(dp[n] > -1)
            return dp[n];
        
        int x = solve(arr, n-2, dp);
        int y = solve(arr, n-1, dp);
        
        return dp[n] = max(arr[n-1]+x, y);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1, -1);
        
        return solve(arr, n, dp);
    }

    // <------- Top-Down ----->

    // int FindMaxSum(int arr[], int n)
    // {
    //     vector<int> dp(n, 0);
        
    //     dp[0] = arr[0];
    //     dp[1] = max(arr[0], arr[1]);
        
    //     for (int i=2; i<n; i++)
    //     {
    //         dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    //     }
        
    //     return dp[n-1];
    // }

};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends