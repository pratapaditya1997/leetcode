class Solution {
public:
    int n, m;
    
    bool ValidCell(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
    
    bool ValidRhombus(int i, int j, int k) {
        if (!ValidCell(i, j)) return false;
        if (!ValidCell(i+k, j+k)) return false;
        if (!ValidCell(i+2*k, j)) return false;
        if (!ValidCell(i+k, j-k)) return false;
        return true;
    }
    
    int left_sum(int x1, int y1, int x2, int y2, vector<vector<int>>& a) {
        if (x2+1 >= n || y2-1 < 0) return a[x1][y1];
        return a[x1][y1] - a[x2+1][y2-1];
    }
    
    int right_sum(int x1, int y1, int x2, int y2, vector<vector<int>>& a) {
        if (x2+1 >= n || y2+1 >= m) return a[x1][y1];
        return a[x1][y1] - a[x2+1][y2+1];
    }
    
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        
        vector<vector<int>> diag_one = g;
        vector<vector<int>> diag_two = g;
        
        for (int j=1; j<m; ++j) {
            for (int i=n-1; i>=0; --i) {
                if (i+1 < n) diag_one[i][j] += diag_one[i+1][j-1];
            }
        }
        
        for (int j=m-2; j>=0; --j) {
            for (int i=n-1; i>=0; --i) {
                if (i+1 < n) diag_two[i][j] += diag_two[i+1][j+1];
            }
        }
        
        set<int> ans;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                for (int k=0; k < min(n,m); ++k) {
                    if (k == 0) {
                        ans.insert(g[i][j]);
                        continue;
                    }
                    if (ValidRhombus(i, j, k)) {
                        int sum = 0;
                        sum += left_sum(i, j, i+k, j-k, diag_one);
                        sum += left_sum(i+k, j+k, i+2*k, j, diag_one);
                        sum += right_sum(i, j, i+k, j+k, diag_two);
                        sum += right_sum(i+k, j-k, i+2*k, j, diag_two);
                        sum -= (g[i][j] + g[i+k][j+k] + g[i+2*k][j] + g[i+k][j-k]);
                        ans.insert(sum);
                    } else break;
                }
            }
        }
        
        vector<int> ret;
        int cnt = 3;
        while (cnt != 0 && !ans.empty()) {
            ret.push_back(*ans.rbegin());
            auto it = ans.end();
            --it;
            ans.erase(it);
            --cnt;
        }
        return ret;
    }
};
