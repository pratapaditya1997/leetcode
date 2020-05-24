/* 
 * Author: aps
 * Time: 2019-11-10 16:38:30
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
    vvi reconstructMatrix(int upper, int lower, vi& colsum) {
        if(accumulate(all(colsum),0) != lower+upper) return {};

        int n = sz(colsum);
        vvi ans(2, vi(n, 0));
        for(int i=0; i<n; i++) {
            if(colsum[i] == 2) {
                if(lower < 1 || upper < 1) return {};
                ans[0][i] = ans[1][i] = 1;
                --lower; --upper;
            }
            if(colsum[i] == 1) {
                if(lower > upper) {
                    if(lower < 1) return {};
                    ans[1][i] = 1;
                    --lower;
                } else {
                    if(upper < 1) return {};
                    ans[0][i] = 1;
                    --upper;
                }
            }
        }
        if(upper || lower) return {};
        return ans;
    }
};

void print(vvi ans) {
    for(int i=0; i<sz(ans); i++) {
        for(auto elem: ans[i]) cout << elem << " ";
        cout << "\n";
    }
    cout << "----" << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vi colsum = {1,1,1};
    vvi ans = sol.reconstructMatrix(2, 1, colsum);
    print(ans);

    colsum = {2, 2, 1, 1};
    ans = sol.reconstructMatrix(2, 3, colsum);
    print(ans);

    colsum = {2,1,2,0,1,0,1,2,0,1};
    ans = sol.reconstructMatrix(5,5,colsum);
    print(ans);
    return 0;
}
