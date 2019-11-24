/* 
 * Author: aps
 * Time: 2019-11-24 20:38:49
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
 
const ll inf = 1e18;
const ll mod = 1e9+7;
 
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
inline ll power(ll a, ll b) {
    ll x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return power(a, mod - 2);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution{
    public:
        int numWays(int k, int n) {
            n = min(n, 500);
            vvl dp(n+1, vl(k+5, 0));
            
            dp[0][0] = 1;
            for(int j=1; j<=k; j++) {
                for(int i=0; i<n; i++) {
                    dp[i][j] = dp[i][j-1];
                    if(i+1 <= n) dp[i][j] = add(dp[i][j], dp[i+1][j-1]);
                    if(i-1 >= 0) dp[i][j] = add(dp[i][j], dp[i-1][j-1]);
                }
            }

            return dp[0][k];
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    cout << sol.numWays(3,2) << endl;
    cout << sol.numWays(2,4) << endl;
    cout << sol.numWays(4,2) << endl;
    return 0;
}
