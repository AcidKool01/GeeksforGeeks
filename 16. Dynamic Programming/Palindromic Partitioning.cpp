#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome (string s, int i, int j)
    {
        // for (int k=i; k<=j; k++)
        // {
        //     if(s[k] != s[j-k-1])
        //         return false;
        // }
        // return true;
        
        if(i>= j) 
            return true;
        return s[i] == s[j] && isPalindrome(s, i+1, j-1);
    }
    
    int solve (string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=j)
            return dp[i][j] = 0;
            
        if (isPalindrome(s, i, j)==true)
            return 0;
            
        if (dp[i][j] != -1)
            return dp[i][j];
            
        int ans = INT_MAX;
            
        for (int k=i; k<=j-1; k++)
        {
            // int temp = solve (s, i, k, dp) + solve (s, k+1, j, dp) + 1; ---> O(n3)

            //below code is basically the optimization of the above as earlier, we assumed that neither
            //of them were solved...but below,  we have checked for that...and, optimized it to O(n2) 

            int left = 0, right = 0;
            
            if (dp[i][k] != -1)
                left = dp[i][k];
            
            else
            {
                left = solve (s, i, k, dp);
                dp[i][k] = left;
            }
            
            if (dp[k+1][j] != -1)
                right = dp[k+1][j];
            
            else
            {
                right = solve (s, k+1, j, dp);
                dp[k+1][j] = right;
            }
            
            int temp = right + left + 1;
            
            ans = min (ans, temp);
        }
        
        return dp[i][j] = ans;
    }

    int palindromicPartition(string str)
    {
        int i = 0;
        int j = str.size()-1;
        
        vector<vector<int>> dp (501, vector<int> (501, -1));
        
        int res = solve (str, i, j, dp);
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}