class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n = *max_element(a.begin(), a.end());
        vector<int> cnt(n+1, 0);
        
        for (int x: a) cnt[x]++;
        
        int prev = cnt[1], prev_prev = 0, temp;
        for (int i=2; i<=n; ++i) {
            temp = prev;
            prev = max(prev, prev_prev + i * cnt[i]);
            prev_prev = temp;
        }
        return prev;
    }
};
