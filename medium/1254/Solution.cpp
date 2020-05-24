/* 
 * Author: aps
 * Time: 2019-11-10 18:17:30
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

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

class Solution {
    bool inValid(int x,int y,vvi&  grid) {
        int n = sz(grid), m = sz(grid[0]);
        return (x<0 || y<0 || x>=n || y>=m || grid[x][y]); 
    }
    
    void fill(int x, int y, vvi& grid) {
        if(inValid(x,y,grid)) return;
        grid[x][y] = 1;
        for(int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            fill(nx, ny, grid);
        }
    }
public:
    int closedIsland(vvi& grid) {
        int n = sz(grid), m = sz(grid[0]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1) fill(i,j,grid);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    fill(i,j,grid);
                }
            }
        }

        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vvi grid = {{1,1,1,1,1,1,1,0},
                {1,0,0,0,0,1,1,0},
                {1,0,1,0,1,1,1,0},
                {1,0,0,0,0,1,0,1},
                {1,1,1,1,1,1,1,0}};
    cout << sol.closedIsland(grid) << "\n";
    return 0;
}
