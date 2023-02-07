#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        // vector<int> temp;
        vector<int> vec(n, 0);

        int count = 0;
        
        for (int i=0; i<n; i++) {
            if(pq.size()<k)
                pq.push(arr[i]);
            
            else if(pq.top()<arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
            
            vec[i] = pq.size() < k ? -1 : pq.top();
        }
       
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
} 