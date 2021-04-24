class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> max_heap;
        for (int i=0; i<n; i++) {
            auto& p = points[i];
            max_heap.push({p[0]*p[0] + p[1]*p[1], i});
            if (max_heap.size() > k) max_heap.pop();
        }
        
        vector<vector<int>> ans;
        while(!max_heap.empty()) {
            int i = max_heap.top().second; max_heap.pop();
            ans.push_back({points[i][0], points[i][1]});
        }
        return ans; 
    }
};
