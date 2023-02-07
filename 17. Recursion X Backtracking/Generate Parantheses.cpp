#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void solve (string output, int n, int op, int en, int i, vector<string> &vec) {
        if(i==2*n) {
            vec.push_back(output);
            output="";
            return;
        }
        
        if(op<n) {
            solve(output+"(", n, op+1, en, i+1, vec);
        } if(en<op) {
            solve(output+")", n, op, en+1, i+1, vec);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> vec;
        solve("", n, 0, 0, 0, vec);
        
        return vec;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 