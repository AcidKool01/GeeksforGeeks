#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {   
        vector<pair<char,int>> T, P;
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 'T')
                T.push_back({arr[i], i});
            else
                P.push_back({arr[i], i});
        }
        
        int i = 0, j = 0;
        
        while(i < T.size() && j < P.size())
        {
            if(abs(P[j].second - T[i].second) <= k)
            {
                count++;
                i++;
                j++;
            }
            
            else if(P[j].second > T[i].second)
                i++;
                
            else
                j++;
        }
        
        return count;
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
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 