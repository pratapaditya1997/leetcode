class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> E,F;
        for(int i: A) {
            for(int j: B) E.push_back(i+j);
        }
        for(int i: C) {
            for(int j: D) F.push_back(i+j);
        }
        sort(F.begin(), F.end());
        int ans = 0;
        for(int x: E) {
            auto p = equal_range(F.begin(), F.end(), -1*x);
            ans += distance(p.first, p.second);
        }
        return ans;
    }
};
