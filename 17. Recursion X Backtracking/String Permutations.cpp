#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(string str, int i, vector<string> &v) {
        if(i==str.size()-1) {
            v.push_back(str);
        }
        
        for (int j=i; j<str.size(); j++) {
            swap(str[i], str[j]);
            solve(str, i+1, v);
            swap(str[i], str[j]);
        }
        
    }
    
    vector<string> permutation(string S)
    {
        vector<string> v;
        solve(S, 0, v);
        sort(v.begin(), v.end());
        
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  