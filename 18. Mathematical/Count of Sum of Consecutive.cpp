// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getCount(int N) {
        // 2*N - l*l + l = 2*a*l
        
        int l=2;
        int count = 0;
        
        while (2*N - l*l + l > 0) {
            if((2*N - l*l + l) % (2*l) == 0) {
                count++;
            }
            l++;
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}  // } Driver Code Ends