#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int count = 1;
        int max = 0;
        int pot = a[0];
        
        for (int i=1; i<size; i++)
        {
            if (a[i]==pot)
                count+=1;
            if (a[i]!=pot)
            {   
                count-=1;
            }
            if (count==-1)
            {   
                count = 1;
                pot = a[i];
            }
        }
        
        for (int i=0; i<size; i++)
        {
            if (pot==a[i])
                max+=1;
        }
        
        if (max>size/2)
            return pot;
            
        else
            return -1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}