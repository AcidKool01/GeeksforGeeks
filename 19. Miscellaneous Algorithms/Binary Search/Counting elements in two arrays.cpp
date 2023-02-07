#include <bits/stdc++.h>
 
using namespace std;


 // } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
    {
        // sort(arr1, arr1+n);
        sort(arr2, arr2+n);
        
        vector<int> res;
        int temp = 0;

        for (int i=0; i<m; i++) {
            int left = 0;
            int right = n-1;
            
            temp = 0;
            
            while (left<=right) {
                int mid = (left+right)/2;
                
                if (arr2[mid]<=arr1[i])
                {
                    left = mid+1;
                }
                
                else {
                    right = mid-1;
                }
            }
            
            res.push_back(right+1);
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
} 