class Solution {
public:
    bool isValidSerialization(const string& s) {
        int slots = 1, n = s.length();
        for (int i=0; i<n; i++) {
            if (s[i] != ',') continue;
            --slots;
            if (slots < 0) return false;
            if (s[i-1] != '#') slots += 2;
        }
        
        slots = (s[n-1] == '#') ? slots - 1 : slots - 1 + 2;
        return (slots == 0);
    }
};
