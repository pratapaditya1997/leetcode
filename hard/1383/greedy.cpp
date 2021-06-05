typedef long long int ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> v;
        for (int i=0; i<n; ++i) {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pii>());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        ll speed_sum = 0, ans = 0;
        for (auto& [cur_eff, cur_speed]: v) {
            pq.push(cur_speed);
            speed_sum += cur_speed;
            if (pq.size() > k) {
                speed_sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speed_sum * cur_eff);
        }
        
        return ans % MOD;
    }
};
