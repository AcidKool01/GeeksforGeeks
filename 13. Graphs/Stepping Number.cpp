#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        queue<int> q;
        int count = 0;
        
        if (n==0)
            count++;
        
        for (int i=1; i<=9; i++)
            q.push(i);
            
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            if (temp>=n && temp<=m)
                count++;
            
            if (temp<=m)
            {
                int last_digit = temp%10;
                
                if(last_digit==0)
                    q.push(10*temp+1);
                
                else if (last_digit==9)
                    q.push(10*temp + 8);
                
                else
                {
                    q.push(10*temp + last_digit-1);
                    q.push(10*temp + last_digit+1);
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}