class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_map<char, int> left, right;
        
        for (char c: s) right[c]++;
        for (char c: s) {
            right[c]--;
            if (right[c] == 0) right.erase(c);
            left[c]++;
            if (left.size() == right.size()) ans++;
        }
        
        return ans;
    }
};
