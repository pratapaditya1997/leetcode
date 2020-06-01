class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int& i: nums) i -= 1;
        sort(nums.begin(), nums.end());
        return (nums[n-2] * nums[n-1]);
    }
};
