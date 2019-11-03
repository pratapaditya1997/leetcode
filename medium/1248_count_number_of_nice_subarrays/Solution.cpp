/* 
 * Author: aps
 * Time: 2019-11-03 14:19:37
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
        int numberOfSubarrays(vi& a, int k) {
            int ans = 0, n = sz(a), cur = 0;
            
            vi cnt(n+1, 0);
            cnt[0] = 1;
            for(int i=0; i<n; i++) {
                cur += ((a[i]&1) ? 1: 0);
                cnt[cur] += 1;
                if(cur >= k) {
                    ans += cnt[cur-k];
                }
            }

            return ans;
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    
    vi arr = {1,1,2,1,1};
    int k = 3;

    cout << sol.numberOfSubarrays(arr, k) << "\n";

    arr = {2,4,6};
    k = 1;
    cout << sol.numberOfSubarrays(arr, k) << "\n";

    arr = {2,2,2,1,2,2,1,2,2,2};
    k = 2;
    cout << sol.numberOfSubarrays(arr, k) << "\n";

    return 0;
}
