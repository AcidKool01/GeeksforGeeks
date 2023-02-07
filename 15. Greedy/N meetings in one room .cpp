#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // static bool (pair<int, int> a, pair<int, int> b)
    //     return a.secon
    
    static bool comparator(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {   
        int count = 0;
        int endl = 0;
        
        vector<pair<int, int>> v;
        for (int i=0 ; i<n; i++)
        {
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), comparator);
        
        for (int i=0; i<n; i++)
        {
            if(v[i].first>endl)
            {
                count+=1;
                endl = v[i].second;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;