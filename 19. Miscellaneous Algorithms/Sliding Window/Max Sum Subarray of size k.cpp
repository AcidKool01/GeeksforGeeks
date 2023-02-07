#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &arr , int N){
        int sum = 0;
        int ans = 0;
        int i=0, j=0;
        
        while(j<N) {
            sum+=arr[j];
            
            if(j<i+K-1) {
                j++;
            }
            
            else if(j==i+K-1) {
                ans = max(ans, sum);
                sum = sum-arr[i];
                i++; j++;
            }
        }
        
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}  