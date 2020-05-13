class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        int n = a.size();
        priority_queue<pair<int,int>> heap;
        
        for(int i=0; i<n; i++) {
            int dist = a[i][0]*a[i][0] + a[i][1]*a[i][1];
            heap.push({dist,i});
            if(heap.size() > k) heap.pop();
        }
        
        vector<vector<int>> ans;
        while(!heap.empty()) {
            auto p = heap.top(); heap.pop();
            ans.push_back({a[p.second][0], a[p.second][1]});
        }
        return ans;
    }
};
