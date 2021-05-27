const int INF = 500;

class Solution {
public:
    int ans = INF, n, m;
    
    /**
    * check if square of size k*k is available from (r,c)
    */
    bool IsAvailable(vector<vector<int>>& a, int r, int c, int k) {
        for (int i=0; i<k; ++i) {
            for (int j=0; j<k; ++j) {
                if (a[r+i][c+j]) return false;
            }
        }
        return true;
    }
    
    void SetRange(vector<vector<int>>& a, int r, int c, int k, int val) {
        for (int i=0; i<k; ++i) {
            for (int j=0; j<k; ++j) {
                a[r+i][c+j] = val;
            }
        }
    }
    
    /**
    * (r, c) is the starting point for selecting a square
    * a records if a cell has been filled or not with a square
    * cur = current min answer
    */
    void Dfs(int r, int c, int cur, vector<vector<int>>& a) {
        // pruning
        if (cur >= ans) return;
        
        // covered the whole rectangle
        if (r >= n) {
            ans = cur;
            return;
        }
        
        // covered till row r fully, now move to next row
        if (c >= m) {
            Dfs(r+1, 0, cur, a);
            return;
        }
        
        // if current cell (r,c) is covered move to next point (r,c+1)
        if (a[r][c]) {
            Dfs(r, c+1, cur, a);
            return;
        }
        
        // try all possible squares starting from (r,c)
        int k = min(n-r, m-c);
        for (k; k >= 1 && IsAvailable(a, r, c, k); --k) {
            SetRange(a, r, c, k, 1);
            Dfs(r, c+1, cur + 1, a);
            SetRange(a, r, c, k, 0);
        }
    }
    
    int tilingRectangle(int N, int M) {
        n = N;
        m = M;
        vector<vector<int>> a(n, vector<int>(m, 0));
        Dfs(0, 0, 0, a);
        return ans;
    }
};
