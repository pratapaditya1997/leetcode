typedef pair<int, int> pii;
typedef long long int ll;

const int INF = 1e9 + 7;

class Solution {
public:
    int minRefuelStops(int target, int start_fuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        
        int ans = 0, prev = 0, tank = start_fuel;
        for (auto& station: stations) {
            tank -= (station[0] - prev);
            while (!pq.empty() && tank < 0) {
                tank += pq.top();
                pq.pop();
                ++ans;
            }
            if (tank < 0) return -1;
            pq.push(station[1]);
            prev = station[0];
        }
        
        tank -= (target - prev);
        while (!pq.empty() && tank < 0) {
            tank += pq.top();
            pq.pop();
            ++ans;
        }
        if (tank < 0) return -1;
        
        return ans;
    }
};
