class MagicDictionary {
private:
    vector<string> dict;
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    }
    
    bool search(string word) {
        bool ans = false;
        int n = word.length();
        
        for (auto& s: dict) {
            int m = s.length();
            if (n != m) continue;
            int mismatch = 0; 
            for (int i=0; i<n; i++) {
                if (s[i] != word[i]) {
                    mismatch++;
                    if (mismatch > 1) break;
                }
            }
            if (mismatch == 1) return true;
        }
        return ans;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
