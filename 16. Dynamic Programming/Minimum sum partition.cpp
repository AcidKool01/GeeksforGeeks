#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:

    // 1: Get the sum of all the elements of the array (sum).
    // 2: Make the sum half (sum/2).
    // 3: Now use subset sum problem here, can you obtain this sum or not. If not which was the last predecessor upto which you were able to do. (total)
    // 4: return sum-2*total.

    // Here, for the initialization part we are filling the dp table with sum values in the dp[0][j] 
    // and for the column values we fill 0 because the sum is 0.
    // What are we storing in dp[i][j]?
    // Basically we are storing how far it is from the mid point of the range between 0----S and 
    // take minimum among them so that we are closer to the midpoint. Also, adding 1 to the answer 
    // if the sum is odd because of the integer division.


	int minDifference(int arr[], int n)  { 
	    int m = 0;
	    for (int i=0; i<n; i++)
	        m+=arr[i];
	    
	    int sum = m;
	   
	    m = m/2;
	        
	    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
	    
	    for (int i=0; i<m+1; i++)
	    {
	        dp[0][i] = i;
	    }
	    
	    for (int i=0; i<n+1; i++)
	        dp[i][0] = 0;
	        
	    
	    for (int i=1; i<n+1; i++)
	    {
	        for (int j=1; j<m+1; j++)
	        {
	            if(arr[i-1]<=j)
	                dp[i][j] = min(dp[i-1][j], dp[i-1][j-arr[i-1]]);
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    return (sum%2==0) ? dp[n][m]*2 : dp[n][m]*2+1;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}