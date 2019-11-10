/* 
 * Author: aps
 * Time: 2019-11-10 19:32:19
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
    int maxScoreWords(vector<string>& w, vector<char>& l, vi& score) {
        vi cnt(26, 0);
        for(char c: l) {
            cnt[c-'a']++;
        }

        int n = sz(w), best = 0;
        for(int i=0; i < (1<<n); i++) {
            vi curCnt = cnt;
            int cur = 0, flag = 1;
            for(int j=0; j<n; j++) {
                if(!flag) break;
                if(i&(1<<j)) {
                    for(int k=0; k < sz(w[j]); k++) {
                        int idx = w[j][k] - 'a';
                        if(curCnt[idx] > 0) {
                            cur += score[idx];
                            curCnt[idx]--;
                        } else {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if(flag) {
                best = max(best, cur);
            }
        }
        return best;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    Solution sol;
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vi score {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout << sol.maxScoreWords(words, letters, score) << "\n";
    return 0;
}
