class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // we need to store {y-x, x} here 
        priority_queue<pair<int,int> > q;
        int n = points.size(), ans = INT_MIN;
        
        for (int i=0; i<n; i++) {
            auto& point = points[i];
            int x = point[0], y = point[1], cur;
            
            // remove points which are at greater than k distance from the queue
            while (!q.empty() && q.top().second < x-k) {
                q.pop();
            }
            
            // compute answer for current point
            if (!q.empty()) {
                auto& best_point = q.top();
                cur = x + y + best_point.first;
                ans = max(ans, cur);
            }
            
            // insert current point the queue
            q.push({y-x, x});
        }
        
        return ans;
    }
};
