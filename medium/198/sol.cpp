class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev = nums[0], prev_prev = 0;
        for (int i=2; i<=n; ++i) {
            int val = max(prev, prev_prev + nums[i-1]);
            prev_prev = prev;
            prev = val;
        }
        
        return prev;
    }
};
