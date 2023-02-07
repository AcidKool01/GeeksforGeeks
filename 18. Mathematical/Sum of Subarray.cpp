#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        long long res = 0;
        long long mod = 1000000007;
        
        for (int i=0; i<n; i++)
        {
            long long x = n-i;       
            long long y = (i+1)*x;

            // x&y ---> for occurence.

            long long z = ((a[i]%mod)*(y%mod))%mod;
            
            res = (res%mod + z%mod)%mod;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}