class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > 15) return false;
        int n = s.length();
        int num = 0, mask = (1<<k)-1, cnt = 0;
        vector<bool> found(1<<k, false);

        for(int i=0; i<n; i++) {
            num = mask & ((num << 1) + s[i] - '0');
            if(!found[num] && i >= k-1) {
                ++cnt;
                found[num] = true;
            }
        }

        return cnt == mask+1;
    }
};