#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        
        vector<int> v(26, 0);
        int count = 0;
        int j = 0;
        
        for (int i=0; i<S.size(); i++)
        {
            v[S[i]-'a']+=1;
            
            while(v[S[i]-'a']>1)
            {
                v[S[j++]-'a']--;
            }
            
            count = max(count, i-j+1);
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } 