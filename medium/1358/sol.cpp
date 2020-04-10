class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(), ans=0, l=0, r=0;
        vector<int> cnt(3,0);
        
        auto ok = [&cnt]() {
            return (cnt[0] && cnt[1] && cnt[2]);
        };
        
        cnt[s[r]-'a']++;
        while(r<n) {
            if(ok()) {
                ans += (n-r);
                cnt[s[l]-'a']--; 
                l++;
            } else {
                r++;
                if(r<n) cnt[s[r]-'a']++;
            }
        }
        return ans;
    }
};
