#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int mini, maxi;
        int res = arr[n - 1] - arr[0];
        for (int i = 1; i <= n - 1; i++)
        {
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
            mini = min(arr[0] + k, arr[i] - k);
            res = min(res, maxi - mini);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;