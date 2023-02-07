#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i ++){
            mp[arr[i]]++;
        }
        
        int size = mp.size();
        unordered_map<int,int>chk;
        int i = 0;
        int j = 0;
        int ret = 0;
        
        while(i <= n)
        {
            if(chk.size() < size)
            {
                chk[arr[i]]++;
                i++;
            }
            else if (chk.size() == size)
            {
                ret += (n - i) + 1;
                
                if(chk[arr[j]] == 1){
                    chk.erase(arr[j]);
                }
                else{
                    chk[arr[j]]--;
                }
                
                j++;
            }
        }
        
        return ret;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}