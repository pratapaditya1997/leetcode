class Solution {
public:
    int uniquePaths(int m, int n) {
        n-=1; m-=1;
        if(m > n) swap(m,n);
        long long res = 1;
        for(int i=n+1; i<=n+m; i++) {
            res *= i;
            res /= (i-n);
        }
        return res;
    }
};
