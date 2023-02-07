#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        int temp = 0;
        vector<int> res;
        
        int a = 0;
        int b= 0;
        int i=0;
        
        while(temp<N)
        {
            a+=candies[i];
            b+=candies[N-i-1];
            i++;
            temp+=K+1;
        }
        
        res.push_back(a);
        res.push_back(b);
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;