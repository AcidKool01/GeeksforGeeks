#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// The idea is to find the equation of the line in simplest form, i.e., in equation ax + by +c, 
// coefficients a, b and c become co-prime. We can do this by calculating the GCD (greatest common divisor) of a, b and c 
// and convert a, b and c in the simplest form. 
// Then, the answer will be (difference of y coordinates) divided by (a) – 1. 
// This is because after calculating ax + by + c = 0, for different y values, x will be number of y values which are exactly divisible by a.

class Solution {
  public:
    int countIntegralPoints(int x1, int y1, int x2, int y2) {
        
        if (x1==x2 && y1==y2)
            return 0;
        
        return __gcd(abs(x1-x2), abs(y1-y2)) - 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1,y1,x2,y2;
        
        cin>>x1>>y1>>x2>>y2;

        Solution ob;
        cout << ob.countIntegralPoints(x1,y1,x2,y2) << endl;
    }
    return 0;
}