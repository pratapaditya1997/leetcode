vector<vector<int>> skip(10, vector<int>(10, 0));

class Solution {
public:
    int f(int cur, int left, vector<int>& vis) {
        if (left < 0) return 0;
        if (left == 0) return 1;
        
        vis[cur] = 1;
        int ret = 0;
        
        for (int i=1; i<10; ++i) {
            if (!vis[i] && (skip[cur][i] == 0 || vis[skip[cur][i]])) {
                ret += f(i, left-1, vis);
            }
        }
        vis[cur] = 0;
        return ret;
    }
    
    int numberOfPatterns(int m, int n) {
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        
        vector<int> vis(10, 0);
        int ans = 0;
        
        for (int len=m; len<=n; ++len) {
            ans += f(1, len-1, vis) * 4; // as 1,3,7,9 are symmetric
            ans += f(2, len-1, vis) * 4; // as 2,4,6,8 are symmetric
            ans += f(5, len-1, vis);
        }
        
        return ans;
    }
};
