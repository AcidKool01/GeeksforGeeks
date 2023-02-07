#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> hash (26, 0);
        for (int i=0; i<s.size(); i++)
            hash[s[i]-'a']++;
            
        priority_queue<int> q;
        for (int i=0; i<26; i++)
        {   
            if (hash[i]>0)
                q.push(hash[i]);
        }
        
        while (!q.empty() and k--){
            int temp = q.top();
            q.pop();
            
            q.push(temp-1);
        }
        
        long long ans = 0;
        
        while (!q.empty()) {
            ans += q.top()*q.top();
            q.pop();
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  