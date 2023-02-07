// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}
// } Driver Code Ends


/*You have to complete this function*/

void solve (string str, string curr, int idx, vector<string> &vec) {
    if(idx==str.length()-1) {
        curr+=str[idx];
        vec.push_back(curr);
        return;
    }
    curr+=str[idx];
    solve(str, curr, idx+1, vec);
    solve(str, curr+" ", idx+1, vec);
}

vector<string>  spaceString(char str[]) {
    vector<string> vec;
    solve(str, "", 0, vec);
    
    return vec;
}