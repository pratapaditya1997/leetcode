class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pos;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) pos.push_back(i);
        }
        
        for(int i=1; i<pos.size(); i++) {
            if(pos[i] - pos[i-1] <= k) return false;
        }
        return true;
    }
};
