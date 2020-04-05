class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n == 0) return 0;
        int min_so_far=prices[0], ans = 0;
        for(int i=1;i<n;i++) {
            ans = max(ans, prices[i] - min_so_far);
            min_so_far = min(min_so_far, prices[i]);
        }
        return ans;
    }
};
