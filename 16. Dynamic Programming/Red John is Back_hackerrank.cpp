#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'redJohn' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
 
int redJohn(int n) {
    int m = 4;
    vector<int> dp(n+1, 0);
    
    dp[0]=0;
    
    dp[1]=dp[2]=dp[3] = 1;
    dp[4]=2;
    
    for (int i=5; i<=n; i++) {
        dp[i] = dp[i-4] + dp[i-1];
    }
    
    int re = dp[n];
    
    long count=0;
    bool prime[re+1];
    for(int i=0;i<=re;i++)
         prime[i] = true;
      
    for(int p = 2; p*p <=re; p++)
        if(prime[p] == true)
            for(int i = p*2; i <= re; i += p)
                prime[i] = false;
      
    for(int i = 2; i <= re; i++)
        if(prime[i] == true)
            count++;
            
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = redJohn(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
