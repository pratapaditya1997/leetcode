class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        while(1) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        fast = nums[0];
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
