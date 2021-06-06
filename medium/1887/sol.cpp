class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> cnt;
        for (int& num: nums) {
            cnt[num]++;
        }
        
        vector<int> v;
        for (auto& [num, freq]: cnt) {
            v.push_back(num);
        }
        
        reverse(begin(v), end(v));
        v.pop_back();
        
        int ans = 0, cur = 0;
        for (int& num: v) {
            cur += cnt[num];
            ans += cur;
        }
        
        return ans;
    }
};
