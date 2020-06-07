const int INF = 1e6;

class Solution {
public:
    // dp[i house][j prev color][k neighbourhoods] = min cost till now
    int dp[101][23][101];

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof dp);
        int ans = f(houses, cost, 0, n+1, target);
        return ans >= INF ? -1 : ans; 
    }

    // min cost when at ith house prev was color of prev house and target is count of neighnourhoods left to make
    int f(vector<int>& h, vector<vector<int>>& cost, int i, int prev, int target) {
        if(i >= size(h)) return target != 0 ? INF : 0;
        if(target < 0) return INF;
        if(dp[i][prev][target] != -1) return dp[i][prev][target];
        
        int ret = INF, new_target = target;
        if(h[i] == 0) {
            // not colored house
            for(int j=0; j<size(cost[i]); j++) {
                new_target = target;
                if(j+1 != prev) new_target -= 1;
                ret = min(ret, cost[i][j] + f(h,cost,i+1,j+1,new_target));
            }
        } else {
            // already colored house
            if(h[i] != prev) new_target -= 1;
            ret = min(ret, f(h,cost,i+1,h[i],new_target));
        }
        return dp[i][prev][target] = ret;
    }
};