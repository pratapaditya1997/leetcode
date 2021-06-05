class Solution {
public:
    int n;
    map<string, vector<string>> m;
    vector<vector<string>> ans;
    
    void BuildPrefixMap(vector<string>& words) {
        m.clear();
        for (auto& word: words) {
            string cur = "";
            for (int i=0; i<n; ++i) {
                cur.push_back(word[i]);
                if (m.find(cur) == m.end()) m[cur] = {};
                m[cur].push_back(word);
            }
        }
    }
    
    void f(int idx, vector<string>& cur) {
        if (idx == n) {
            ans.push_back(cur);
            return;
        }
        
        string pre = "";
        for (auto& str: cur) {
            pre.push_back(str[idx]);
        }
        
        if (m.find(pre) == m.end()) return;
        
        vector<string> options = m[pre];
        for (auto& option: options) {
            cur.push_back(option);
            f(idx+1, cur);
            cur.pop_back();
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].length();
        ans.clear();
        
        BuildPrefixMap(words);
        
        for (auto& word: words) {
            vector<string> cur{word};
            f(1, cur);
        }
        return ans;
    }
};
