/* 
 * Author: aps
 * Time: 2019-11-24 19:51:45
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
        vector<vector<string>> suggestedProducts(vector<string>& p,string str) {
            map<string, vector<string>> sugs;
            sort(all(p));
            for(string v: p) {
                int n = sz(v);
                for(int i=0; i<n; i++) {
                    string pref = v.substr(0,i+1);
                    sugs[pref].pb(v);
                }
            }

            int m = sz(str);
            vector<vector<string>> ans(m);
            string cur = "";
            for(int i=0; i<m; i++) {
                cur += str[i];
                vector<string> possible;
                if(sugs.find(cur) != sugs.end()) {
                    vector<string> v = sugs[cur];
                    int take = min(3, sz(v));
                    for(int j=0; j<take; j++) possible.pb(v[j]);
                }
                ans[i] = possible;
            }
            return ans;
        }
};

void print(vector<vector<string>> ans) {
    for(auto v: ans) {
        for(auto x: v) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vector<string> p = {"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> ans =  sol.suggestedProducts(p, "mouse");
    print(ans);

    p = {"bags","baggage","banner","box","cloths"};
    ans = sol.suggestedProducts(p, "bags");
    print(ans);

    p = {"havana"};
    ans = sol.suggestedProducts(p, "tatiana");
    print(ans);
    return 0;
}
