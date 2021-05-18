class RangeModule {
    set<pair<int,int>> s;
    
public:
    RangeModule() {}
    
    void addRange(int x, int y) {
        auto it = s.upper_bound({x, INT_MAX});
        if (it != s.begin()) {
            --it;
            if (it->second < x) ++it;
            else {
                // overlap with prev interval
                // it currently points to the prev pair
                x = it->first;
                y = max(it->second, y);
                // erase return iterator to next item or end() if no more elements are present
                it = s.erase(it);
            }
        }
        while (it != s.end() and it->first <= y) {
            y = max(y, it->second);
            it = s.erase(it);
        }
        s.insert({x, y});
    }
    
    bool queryRange(int x, int y) {
        auto it = s.upper_bound({x, INT_MAX});
        return (it != s.begin() && (--it)->second >= y);
    }
    
    void removeRange(int x, int y) {
        auto it = s.upper_bound({x, INT_MAX});
        vector<pair<int,int>> tmp;
        if (it != s.begin()) {
            --it;
            if (it->second <= x) ++it;
            else {
                tmp.push_back({it->first, x});
                if (it->second > y) tmp.push_back({y, it->second});
                it = s.erase(it);
            }
        }
        while (it != s.end() && it->first < y) {
            if (it->second > y) tmp.push_back({y, it->second});
            it = s.erase(it);
        }
        for (auto p: tmp) s.insert(p);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
