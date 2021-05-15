class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        
        // transpose
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans[j][i] = box[i][j];
            }
        }
        
        // reflect
        for (int i=0; i<m; i++) {
            for (int j=0; j<n/2; j++) {
                int tmp = ans[i][j];
                ans[i][j] = ans[i][n - j -1];
                ans[i][n - j - 1] = tmp; 
            }
        }
        
        auto fill_up = [&](int x, int y, int stones, int prev_obs) {
            while(stones) {
                ans[x][y] = '#';
                --x;
                --stones;
            }
            while(x > prev_obs) {
                ans[x][y] = '.';
                --x;
            }
        };
        
        cout << m << " " << n; 
        for (int j=0; j<n; j++) {
            int cur = 0, prev_obs = -1;
            for (int i=0; i<m; i++) {
                if (ans[i][j] == '#') ++cur;
                else if (ans[i][j] == '.');
                else {
                    fill_up(i - 1, j, cur, prev_obs);
                    cur = 0;
                    prev_obs = i;
                }
            }
            fill_up(m-1, j, cur, prev_obs);
        }
        
        return ans;
    }
};
