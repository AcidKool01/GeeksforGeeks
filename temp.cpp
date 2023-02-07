#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
//#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if
#define test   cout<<" We Droped up Here Boss _________________ "<<endl
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define txt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ld long double
#define vb vector<bool>
#define getlost {cout<<"NO"<<endl;return ;}
#define getgud {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define inp(v,n) for(int i = 0 ;  i<n;i++)cin>>v[i];
#define outp(v) for(auto ele : v){        cout << ele.first << " " << ele.second << " ";}cout<<endl
const ll mod = 1e9 + 7;
#define summ(v,sum) for(auto ele : v)sum+=ele;
#define inti int i
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define fo(i,a,b) for(int i = a ; i<=b;i++)
#define outq(q)     queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();};
#define sttk(x) static_cast<ll>(x)
#define re register
#define intj int j
const int OO = 1e6;
inline int gcd(re int x, re int y) {
    return y ? gcd(y, x % y) : x;
}
inline int LCM(re int x, re int y) {
    return x / gcd(x, y) * y;
}
ll comb(ll n, ll r)//nCr
{
    ll top = 1;
    ll bot = 1;
    if (n - r > r)
    {
        r = n - r;
    }

    if (r != 0)
    {
        while (r) {
            top *= n;
            bot *= r;
            ll m = gcd(top, bot);
            top /= m;
            bot /= m;
            n--;
            r--;
        }
    }
    else
        top = 1;
    return top;
}
//----------------------Code Starts Here-----------------------------//
map<ll, ll>dp;
ll solve(ll n) {
    if (n < 1) {
        return n;
    }
    if (dp[n] > 0)return dp[n];
    return dp[n] = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
}
void solve() {
    ll n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }
}
int main() {
    Silver_is_better_than_Gold;
    // For getting input from input.txt file
 //  freopen("alimagde.in", "r", stdin);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {

        solve();
    }
}//-