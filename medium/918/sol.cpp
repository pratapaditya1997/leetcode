class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, ansMax = nums[0], curMax = 0, ansMin = nums[0], curMin = 0;
        for (int& num: nums) {
            curMax = max(curMax + num, num);
            ansMax = max(ansMax, curMax);
            
            curMin = min(curMin + num, num);
            ansMin = min(ansMin, curMin);
            
            total += num;
        }
        if (ansMax > 0) return max(ansMax, total - ansMin);
        return ansMax;
    }
};
