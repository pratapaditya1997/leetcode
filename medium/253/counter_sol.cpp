const int N = 1e6 + 6;
vector<int> cnt(N);

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        fill(cnt.begin(), cnt.end(), 0);
        for (auto& interval: intervals) {
            cnt[interval[0]]++;
            cnt[interval[1]]--;
        }
        
        int ans = 0, cur = 0;
        for (int i=0; i<N; i++) {
            cur += cnt[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
