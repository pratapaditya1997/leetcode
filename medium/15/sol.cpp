class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=n-1, sum=0;
            while(l < r) {
                int lval = nums[l], rval = nums[r];
                sum = nums[i] + lval + rval;
                if(sum == 0) ans.push_back(vector<int>{nums[i],lval,rval});
                if(sum <= 0) while(l<r && nums[l] == lval) l++;
                if(sum >= 0) while(l<r && nums[r] == rval) r--;
            }
        }
        
        return ans;
    }
};
