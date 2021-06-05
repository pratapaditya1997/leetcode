class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> x_map;
        unordered_map<int, vector<int>> y_map;
        set<int> x_set;
        
        for (auto& p: points) {
            int x = p[0], y = p[1];
            if (x_map.find(x) == x_map.end()) x_map[x] = {};
            if (y_map.find(y) == y_map.end()) y_map[y] = {};
            x_map[x].push_back(y);
            y_map[y].push_back(x);
            x_set.insert(x);
        }
        
        for (auto& p: y_map) {
            sort(p.second.begin(), p.second.end());
        }
        
        int ans = INT_MAX;
        for (int x: x_set) {
            vector<int> y_list = x_map[x];
            
            int sz = y_list.size();
            for (int i=0; i<sz; ++i) {
                for (int j=i+1; j<sz; ++j) {
                    int y1 = y_list[i], y2 = y_list[j];
                    vector<int> y1_set = y_map[y1];
                    vector<int> y2_set = y_map[y2];
                    vector<int> inter;
                    set_intersection(y1_set.begin(), y1_set.end(),y2_set.begin(), y2_set.end(),back_inserter(inter));
                    
                    int len = abs(y2 - y1);
                    for (int x2: inter) {
                        if (x == x2) continue;
                        ans = min(ans, len * abs(x2 - x));
                    }
                }
            }
        }
        
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
