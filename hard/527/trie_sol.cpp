typedef pair<string, int> psi;

const int ALPHA = 26;

int nodes;
vector<vector<int>> trie;
vector<int> words_count;

void Init(int len) {
    nodes = 0;
    trie = vector<vector<int>>(len, vector<int>(ALPHA, -1));
    words_count.assign(len, 0);
}

int AddEdge(int node, char c) {
    int nxt = trie[node][c - 'a'];
    if (nxt == -1) {
        nxt = ++nodes;
        trie[node][c - 'a'] = nxt;
    }
    return nxt;
}

void Insert(const string& str) {
    int cur = 0;
    for (char c: str) {
        ++words_count[cur];
        cur = AddEdge(cur, c);
    }
    ++words_count[cur];
}

int Search(const string& str) {
    int cur = 0, ret = 0;
    for (char c: str) {
        int nxt = trie[cur][c - 'a'];
        if (words_count[cur] == 1) return ret;
        cur = nxt;
        ++ret;
    }
    return ret;
}

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
            auto grp = p.second; // get group of strings under current abbreviation
            
            int word_len = 0;
            for (auto& str_idx: grp) {
                word_len += str_idx.first.length();
            }
            
            Init(word_len + 5);
            for (auto& str_idx: grp) {
                string str = str_idx.first;
                Insert(str); // insert string to the trie
            }
            
            for (auto& str_idx: grp) {
                string str = str_idx.first;
                int idx = str_idx.second;
                int lcp = Search(str);  // search for the lcp of current string in the current trie
                if (lcp != 0) --lcp;
                ans[idx] = Abbreviate(str, lcp);
            }
        }
        
        return ans;
    }
};
