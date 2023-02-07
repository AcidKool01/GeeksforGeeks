
// Meet in the middle Algorithm

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void solve (int arr[], int i, int n, int &count, int k, int pr) {
        
        if(i>=n || pr>k)
            return;
        
        
        if(pr*arr[i]<=k)
            count++;
        
        solve(arr, i+1, n, count, k, pr*arr[i]);
        solve(arr, i+1, n, count, k, pr);
    }
  
    int numOfSubsets(int arr[], int N, int K) {
        int count = 0;
        solve(arr, 0, N, count, K, 1);
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  