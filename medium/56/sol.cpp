class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return intervals;
        
        vector<pair<int,int>> vec, ans;
        for(auto v: intervals) vec.push_back({v[0], v[1]});
        sort(vec.begin(), vec.end());
    
        for(auto curPair: vec) {
            if(!ans.empty() && ans.back().second >= curPair.first) {
                ans.back().second = max(ans.back().second, curPair.second);
            } else ans.push_back(curPair);
        }
        
        vector<vector<int>> ret;
        for(auto curPair: ans) {
            vector<int> newInterval{curPair.first, curPair.second};
            ret.push_back(newInterval);
        }
        
        return ret;
    }
};
