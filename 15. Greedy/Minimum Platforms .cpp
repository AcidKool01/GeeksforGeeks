#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    // bool myComp(pair<int, int> a, pair<int, int> b)
    //     return a.second<b.second;
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>> v;
    	int count = 1;
    	
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	for (int i=0; i<n; i++)
    	{
    	    v.push_back({arr[i], dep[i]});
    	}

    	int j = 0;
    	
    	sort(v.begin(), v.end());
    	
    	for (int i=1; i<n; i++)
    	{
    	    if(v[i].first<=v[j].second)
    	    {
    	        count+=1;
    	    }
    	    else
    	        j++;
    	}
    	
    	return count;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;