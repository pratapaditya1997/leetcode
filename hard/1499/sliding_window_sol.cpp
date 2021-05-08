class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // we need to store {x, y-x} here 
        deque<pair<int,int> > q;
        int n = points.size(), ans = INT_MIN;
        
        for (int i=0; i<n; i++) {
            auto& point = points[i];
            int x = point[0], y = point[1], cur;
            
            // remove points which are at greater than k distance from the queue
            while (!q.empty() && q.front().first < x-k) {
                q.pop_front();
            }
            
            // compute answer for current point
            if (!q.empty()) {
                auto& best_point = q.front();
                cur = x + y + best_point.second;
                ans = max(ans, cur);

                // update the queue
                while (!q.empty() && y-x >= q.back().second) {
                    q.pop_back();
                }
            }
            
            // insert current point the queue
            q.push_back({x, y-x});
        }
        
        return ans;
    }
};
