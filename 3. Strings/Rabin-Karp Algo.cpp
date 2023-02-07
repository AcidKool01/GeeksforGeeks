#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int M = pat.size(); 
            int N = txt.size(); 
            int i, j; 
            int p = 0; 
            int t = 0; 
            int h = 1; 
            vector<int> vec;

            for (i = 0; i < M - 1; i++) 
                h = (h * 256) % 101; 
          
            for (i = 0; i < M; i++) 
            { 
                p = (256 * p + pat[i]) % 101; 
                t = (256 * t + txt[i]) % 101; 
            } 
            
            for (i = 0; i <= N - M; i++) 
            { 
                if ( p == t ) 
                { 
                    for (j = 0; j < M; j++) 
                    { 
                        if (txt[i+j] != pat[j]) 
                            break; 
                    } 
                    if (j == M) 
                        vec.push_back(i+1);
                } 
                
                if ( i < N-M ) 
                { 
                    t = (256*(t - txt[i]*h) + txt[i+M])%101; 
                    if (t < 0) 
                    t = (t + 101); 
                } 
            } 
            if (vec.empty())
                vec.push_back(-1);
                
            return vec;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}