// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int arr[], int n, int l, int r)
    {
        long count=0, i=0, j=0, ans=0;
        for(j=0; j<n; j++)
        {
            if(arr[j]<=r && arr[j]>=l)
            {
                count=j-i+1;
            }
            else if(arr[j]>r)
            {
                count=0;
                i=j+1;
            }
            ans+=count;
        }
        return ans;
    }
};

// { Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}
  // } Driver Code Ends