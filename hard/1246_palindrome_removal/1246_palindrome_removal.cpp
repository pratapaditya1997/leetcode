/* 
 * Author: aps
 * Time: 2019-11-03 13:22:17
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

class Solution {
    public:
        int minimumMoves(vi& a) {
            int n = sz(a);
            vvi dp(n, vi(n, n));

            for(int l=n-1; l>=0; --l) {
                for(int r=l; r<n; ++r) {
                    if(l == r) {
                        dp[l][r] = 1;
                        continue;
                    }
                    if(l+1 == r) {
                        dp[l][r] = 2;
                        if(a[l] == a[r]) {
                            dp[l][r] = 1;
                        }
                        continue;
                    }
                    dp[l][r] = dp[l+1][r-1] + (a[l] == a[r] ? 0 : 2);
                    for(int i=l; i<r; ++i) {
                        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
                    }
                }
            }

            return dp[0][n-1];
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;

    vi arr = {1,2};
    cout << sol.minimumMoves(arr) << "\n";

    arr = {1,3,4,1,5};
    cout << sol.minimumMoves(arr) << "\n";
    return 0;
}
