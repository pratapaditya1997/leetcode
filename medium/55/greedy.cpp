class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), rightmost = 0;
        for(int i=0; i<n && i<=rightmost; i++) {
            if(i+nums[i] >= rightmost) {
                rightmost = i+nums[i];
            }
        }
        
        return (rightmost >= n-1);
    }
};
