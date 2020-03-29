#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=n-1;i>=0;i--){
            int tempi = i,j = 0;
            vi diag;
            while(1) {
                if(tempi == n || j == m) break;
                diag.pb(mat[tempi][j]);
                tempi++; j++;
            }
            sort(all(diag));
            tempi = i, j = 0;
            int k = 0;
            while(1) {
                if(tempi == n || j == m) break;
                mat[tempi][j] = diag[k++];
                tempi++; j++;
            }
        }
        for(int j=1; j<m; j++) {
            int i=0, tempj = j;
            vi diag;
            while(1) {
                if(i == n || tempj == m) break;
                diag.pb(mat[i][tempj]);
                i++; tempj++;
            }
            sort(all(diag));
            i = 0, tempj = j;
            int k = 0;
            while(1) {
                if(i == n || tempj == m) break;
                mat[i][tempj] = diag[k++];
                i++; tempj++;
            }
        }
        return mat;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vvi mat = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    vvi ans = sol.diagonalSort(mat);
    for(int i=0;i<(int)ans.size();i++){
        for(int j=0;j<(int)ans[0].size();j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}