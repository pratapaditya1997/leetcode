class Solution {
public:
    int dp[101][101][101] = {};

    int f(vector<int>& h, int i, int j, int k) {
        if(i >= size(h) || k <= 0) {
            return (i == size(h) && k == 0) ? 0 : INT_MAX;
        }
        if(dp[i][j][k]) return dp[i][j][k];
        dp[i][j][k] = f(h, i+1, i+1, k-1);
        if(dp[i][j][k] != INT_MAX) {
            for(int p=j; p<=i; p++) {
                dp[i][j][k] += abs(h[(i+j)/2]-h[p]);
            }
        }
        return dp[i][j][k] = min(dp[i][j][k], f(h,i+1,j,k));
    }

    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses), end(houses));
        return f(houses, 0, 0, k);
    }
};