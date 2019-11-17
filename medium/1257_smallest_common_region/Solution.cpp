/* 
 * Author: aps
 * Time: 2019-11-17 18:57:43
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
    void print(vector<string> path) {
        for(string str: path) cout << str << " ";
        cout << "\n";
    }

    void printMap(map<string,string>& par) {
        for(auto elem: par) {
            cout << elem.fi << " " << elem.se << "\n";
        }
    }
public:
    string findSmallestRegion(vector<vector<string>>& regions, string r1, string r2) {
        map<string, string> parent;
        int n = sz(regions);
        for(int i=0; i<n; i++) {
            for(string r: regions[i]) {
                if(r != regions[i][0]) parent[r] = regions[i][0];
            }
        }
        //printMap(parent);

        vector<string> p1, p2;
        while(1) {
            p1.pb(r1);
            if(parent.find(r1) != parent.end()) r1 = parent[r1];
            else break;
        }
        while(1) {
            p2.pb(r2);
            if(parent.find(r2) != parent.end()) r2 = parent[r2];
            else break;
        }

        //print(p1);
        //print(p2);

        string ans = "";
        reverse(all(p1));
        reverse(all(p2));
        int n1 = sz(p1), n2 = sz(p2);
        for(int i=0; i<min(n1,n2); i++) {
            if(p1[i] != p2[i]) break;
            ans = p1[i];
        }

        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vector<vector<string>> regions = {{"Earth","North America","South America"},
                                      {"North America","United States","Canada"},
                                      {"South America","Brazil"},
                                      {"United States","New York","Boston"},
                                      {"Canada","Quebec"}};
    cout << sol.findSmallestRegion(regions, "Quebec", "New York") << "\n";
    return 0;
}
