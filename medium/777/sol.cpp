typedef pair<char, int> pci;

class Solution {
public:  
    bool canTransform(string s, string t) {
        int n = s.length();
        
        vector<pci> s_pos, t_pos;
        for (int i=0; i<n; i++) {
            if (s[i] != 'X') s_pos.push_back({s[i], i});
            if (t[i] != 'X') t_pos.push_back({t[i], i});
        }
        
        if (s_pos.size() != t_pos.size()) return false;
        
        n = s_pos.size();
        for (int i=0; i<n; i++) {
            if (s_pos[i].first != t_pos[i].first) return false;
            if (s_pos[i].first == 'L' && t_pos[i].second > s_pos[i].second) return false;
            if (s_pos[i].first == 'R' && t_pos[i].second < s_pos[i].second) return false;
        }
        
        return true;
    }
};
