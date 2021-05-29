typedef long long int ll;

const ll MOD = 1e9 + 7;

inline ll Add(ll x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline ll Mul(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

template<class T>
struct Matrix {
    vector<vector<T>> d;
    int n, m;
    
    Matrix(int _n, int _m): n(_n), m(_m) {
        d = vector<vector<T>> (n, vector<T>(m, 0));
    }
    
    Matrix operator + (const Matrix& mat) {
        Matrix ret(n, m);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                ret.d[i][j] = Add(d[i][j], mat.d[i][j]);
            }
        }
        return ret;
    }
    
    Matrix operator * (const Matrix& mat) {
        Matrix ret(n, mat.m);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<mat.m; ++j) {
                for (int k=0; k<m; ++k) {
                    ret.d[i][j] = Add(ret.d[i][j], Mul(d[i][k], mat.d[k][j]));
                }
            }
        }
        return ret;
    }
    
    Matrix operator ^ (ll p) {
        Matrix ret(n, n), base(*this);
        for (int i=0; i<n; ++i) ret.d[i][i] = 1;
        
        for (; p; p/=2) {
            if (p&1) ret = ret * base;
            base = base * base;
        }
        return ret;
    }
};

class Solution {
public:
    int numOfWays(int n) {
        if (n == 1) return 12;
        
        Matrix<ll> a(2, 2);
        a.d[0][0] = 3; a.d[0][1] = 2;
        a.d[1][0] = 2; a.d[1][1] = 2;
        
        Matrix<ll> res = a ^ (n-1);
        ll ans = Add(Mul(res.d[0][0], 6), Mul(res.d[0][1], 6));
        ans = Add(ans, Mul(res.d[1][0], 6));
        ans = Add(ans, Mul(res.d[1][1], 6));
        
        return ans;
    }
};
