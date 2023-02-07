#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        int n = A.size();
        int m = B.size();
        int ans = 0;
        
        if(n!=m)
            return -1;
        
        int aHash[256] = {0};
        int bHash[256] = {0};
        
        for (int i=0; i<n; i++)
            aHash[A[i]]++;
        
        for (int i=0; i<m; i++)
            bHash[B[i]]++;
            
        for (int i=0; i<256; i++)
            if(aHash[i] != bHash[i])
                return -1;
        
        for (int i=n-1, j=n-1; i>=0; )
        {
            while (i>=0 && A[i] != B[j])
            {
                i--;
                ans++;
            }
            
            if(i>=0)
            {
                i--; j--;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}