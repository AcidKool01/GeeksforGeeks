// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        int arr[n + 1];
        memset(arr, 0, sizeof arr);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                arr[j] = max(arr[j - i] + price[i - 1], arr[j]);

        return arr[n];
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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends