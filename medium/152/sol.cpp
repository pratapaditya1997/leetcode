class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<int> maxi(n), mini(n);
        
        maxi[0] = nums[0], mini[0] = nums[0], ans = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] > 0) {
                maxi[i] = max(nums[i], nums[i]*maxi[i-1]);
                mini[i] = min(nums[i], nums[i]*mini[i-1]);
            } else {
                maxi[i] = max(nums[i], nums[i]*mini[i-1]);
                mini[i] = min(nums[i], nums[i]*maxi[i-1]);
            }
            ans = max(ans, maxi[i]);
        }
        
        return ans;
    }
};
