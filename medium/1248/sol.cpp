class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, odds = 0;
        vector<int> count(n+1,0);
        
        count[0] = 1;
        for(int i: nums) {
            if(i&1) odds++;
            count[odds]++;
            if(odds>=k) ans += count[odds-k];
        }
        return ans;
    }
};
