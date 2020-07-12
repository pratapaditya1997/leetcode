class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n = size(a);
        vector<vector<int>> ans;
        vector<int> cur;
        
        function<void(int,int)> f = [&](int pos, int sum) {
            if(sum > target || pos >= n) return;
            if(sum == target) {
                ans.push_back(cur);
                return;
            }
            f(pos+1,sum);
            cur.push_back(a[pos]);
            f(pos,sum+a[pos]);
            cur.pop_back();
        };
        
        f(0,0);
        return ans;
    }
};
