#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  
    long long int solve (int n, int m, int S[], vector<vector<long long int>> &output)
    {
        if(n==0)
            return 1;
        
        if(n<0)
            return 0;
        
        if(output[n][m]>-1)
            return output[n][m];
            
        if(m==0)
            return 0;
            
        long long int first = solve(n-S[0], m, S, output);
        long long int second = solve(n, m-1, S+1, output);
        
        output[n][m] = first + second;
        
        return first+second;
        
    }
  
    long long int count( int S[], int m, int n )
    {
        vector<vector<long long int>> output (n+1, vector<long long int> (m+1));
        
        for (int i=0; i<n+1; i++)
        {
            for (int j=0; j<m+1; j++)
                output[i][j] = -1;
        }
        
        long long int ans = solve(n, m, S, output);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends