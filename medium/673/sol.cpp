class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> len(n, 0), cnt(n,0);
        
        for (int i=0; i<n; ++i) {
            len[i] = cnt[i] = 1;
            for (int j=0; j<i; ++j) {
                if (a[j] >= a[i]) continue;
                if (len[i] == len[j] + 1) {
                    cnt[i] += cnt[j];
                } else if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
        }
        
        int best = 1, ans = 0;
        for (int i=0; i<n; ++i) {
            if (len[i] == best) ans += cnt[i];
            else if (len[i] > best) {
                best = len[i];
                ans = cnt[i];
            }
        }
        return ans;
    }
};
