#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int length1 = str.length();
        int length2 = pattern.length();
        vector<vector<int>> dp (length2+1, vector<int>(length1+1,0));

        dp[0][0] = 1;
        
        for(int i=1;i<=length1;i++)
        {
            if(str[i]=='*' && dp[0][i-1]==1)
                dp[0][i] = 1;
            
            else
                dp[0][i] = 0;
        }
        
        for(int i =1;i<=length2;i++)
        {
            if(pattern[i-1] == '*' && dp[i-1][0] == 1)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        
        for(int i=1;i<=length2;i++)
        {
            for(int j=1;j<=length1;j++)
            {
                if(pattern[i-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            
                else if(pattern[i-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                
                else if(pattern[i-1] == str[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                else if(pattern[i-1] != str[j-1])
                    dp[i][j] = 0;
            }
        }
        return dp[length2][length1];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}