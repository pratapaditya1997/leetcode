class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre_sum(k + 1, 0), suf_sum(k + 1, 0);
        
        pre_sum[0] = suf_sum[0] = 0;  
        for (int i=0; i<k; i++) {
            pre_sum[i + 1] = a[i] + pre_sum[i];
            suf_sum[i + 1] = a[n - i -1] + suf_sum[i];
        }
        
        int best = 0;
        for (int i=0; i<=k; i++) {
            int cur = pre_sum[i] + suf_sum[k - i];
            best = max(best, cur);
        }
        
        return best;
    }
};
