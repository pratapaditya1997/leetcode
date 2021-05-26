typedef pair<string, int> psi;

class Solution {
public:
    /**
    * abbreviate the given string, while keeping first i items intact
    * if abbreviating is not making string smaller, return original string
    */
    string Abbreviate(string word, int i) {
        int n = word.length();
        if (n - i <= 3) return word;
        return word.substr(0, i + 1) + to_string(n - i - 2) + word[n-1];
    }
    
    /**
    * returns length of common prefix
    */
    int LCP(const string& s, const string& t) {
        int i = 0, n = s.length(), m = t.length();
        while (i < n && i < m && s[i] == t[i]) {
            ++i;
        }
        return i;
    }
    
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();
        
        map<string, vector<psi>> m;
        vector<string> ans(n);
        
        for (int i=0; i<n; ++i) {
            string abr = Abbreviate(words[i], 0);
            if (m.find(abr) == m.end()) m[abr] = {};
            m[abr].push_back({words[i], i});
        }
        
        for (auto& p: m) {
            auto grp = p.second;
            sort(grp.begin(), grp.end());
            
            vector<int> lcp(grp.size());
            for (int i=1; i<grp.size(); ++i) {
                int p = LCP(grp[i-1].first, grp[i].first);
                lcp[i] = p;
                lcp[i-1] = max(lcp[i-1], p);
            }
            
            for (int i=0; i<grp.size(); ++i) {
                ans[grp[i].second] = Abbreviate(grp[i].first, lcp[i]);
            }
        }
        
        return ans;
    }
};
