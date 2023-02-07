#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        int temp=0;
        int i=0, j=0;
        
        // priority_queue<int> q;
        deque<int> q;
        
        while (j<n) {
            
            while(!q.empty() && q.back() < arr[j])
                q.pop_back();
            
            q.push_back(arr[j]);

            if(j==i+k-1) {
                res.push_back(q.front());
                
                if(q.front()==arr[i])
                    q.pop_front();
                    
                i++; j++;
            }
            
            else 
                j++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}