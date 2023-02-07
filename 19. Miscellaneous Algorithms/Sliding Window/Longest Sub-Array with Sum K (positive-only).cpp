#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int K) 
    { 
        int i=0, j=0, sum=0, count=0;
        
        while(j<n) {
            sum+=arr[j];
            
            if(sum<K) {
                j++;
            }
            
            else if(sum==K) {
                count=max(count, j-i+1);
                j++;
            }
            
            else if(sum>K) {
                
                while(sum>K){
                    sum-=arr[i];
                    i++;
                }
                j++;
            }
        }
        
        return count;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
} 