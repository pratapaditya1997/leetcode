class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> powerSet;
        for(int i=0; i<(1<<n); i++) {
            vector<int> currentSet;
            for(int j=0; j<n; j++) {
                if(i&(1<<j)) {
                    currentSet.push_back(nums[j]);
                }
            }
            powerSet.push_back(currentSet);
        }
        return powerSet;
    }
};
