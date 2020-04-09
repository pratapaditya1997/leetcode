class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a+b+c;
        vector<pair<int,char>> count{{a,'a'},{b,'b'},{c,'c'}};
        
        string ans = "";
        for(int i=0; i<n; i++) {
            sort(count.begin(), count.end());
            for(int j=2; j>=0; j--) {
                if(count[j].first == 0) break;
                if(i>=2) {
                    if(!(ans[i-1] == count[j].second && ans[i-2] == count[j].second)) {
                        ans += count[j].second;
                        count[j].first -= 1;
                        break;
                    }
                } else {
                    ans += count[j].second;
                    count[j].first -= 1;
                    break;
                }
            }
            if(ans.length() == i) break;
        }
        return ans;
    }
};
