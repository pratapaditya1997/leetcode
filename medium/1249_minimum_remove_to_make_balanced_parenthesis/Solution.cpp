/* 
 * Author: aps
 * Time: 2019-11-03 23:15:29
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

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vi valid(n, 1);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(!stk.empty()) {
                    stk.pop();
                } else valid[i] = 0;
            }
        }
        while(!stk.empty()) {
            valid[stk.top()] = 0;
            stk.pop();
        }

        string ans = "";
        for(int i=0; i<n; i++) {
            if(valid[i]) ans += s[i];
        }

        return ans;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    cout << sol.minRemoveToMakeValid("lee(t(c)o)de)") << "\n";
    cout << sol.minRemoveToMakeValid("a)b(c)d") << "\n";
    cout << sol.minRemoveToMakeValid("))((") << "\n";
    cout << sol.minRemoveToMakeValid("(a(b(c)d)") << "\n";
    return 0;
}
