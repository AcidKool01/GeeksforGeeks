#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        pair<int, int> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int currMax = INT_MIN, currMin = INT_MAX;
        
        for (int i=0; i<k; i++) {
            minHeap.push({arr[i][0], {i, 0}});
            currMax = max(currMax, arr[i][0]);
        }
        
        int range = INT_MAX;
        int start=0, end=0;
        
        while(true) {
            pair<int, pair<int, int>> top = minHeap.top();
            minHeap.pop();
            
            currMin = top.first;
            
            if(currMax-currMin<range) {
                start = currMin, end = currMax;
                range = currMax-currMin;
            }
            
            if(top.second.second +1 ==n) {
                break;
            }
            
            minHeap.push({arr[top.second.first][top.second.second+1], {top.second.first, top.second.second+1}});
            
            if(arr[top.second.first][top.second.second+1]>currMax) {
                currMax = arr[top.second.first][top.second.second+1];
            }
            
        }
        
        ans = {start, end};
        
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}