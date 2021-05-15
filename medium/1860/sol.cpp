class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        set<pair<int,int>> s;
        s.insert({-1 * m1, 1});
        s.insert({-1 * m2, 2});
        
        int i = 1;
        while (1) {
            int mem = -1 * s.begin()->first;
            int type = s.begin()->second;
            s.erase(s.begin());
            
            if (mem < i) break;
            
            if (type == 1) m1 -= i;
            else m2 -= i;
            
            mem -= i;
            ++i;
            s.insert({-1 * mem, type});
        }
        
        vector<int> ans{i, m1, m2};
        return ans;
    }
};
