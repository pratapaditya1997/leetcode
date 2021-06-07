typedef pair<int, pair<int, string>> piis;

class AutocompleteSystem {
private:
    int n;
    map<string, int> freq;
    vector<string> words;
    string cur_query;
    
    int nodes;
    vector<vector<int>> trie, node_idx;
    
    void Init(int len) {
        nodes = 0;
        cur_query = "";
        
        trie = vector<vector<int>> (len, vector<int> (128, -1));
        node_idx = vector<vector<int>> (len, vector<int>());
    }
    
    int AddEdge(int node, char& c) {
        int& nxt = trie[node][(int)c];
        if (nxt == -1) nxt = ++nodes;
        return nxt;
    }
    
    void Insert(const string& s, int idx) {
        int cur = 0;
        for (char c: s) {
            node_idx[cur].push_back(idx);
            cur = AddEdge(cur, c);
        }
        node_idx[cur].push_back(idx);
    }
    
    vector<int> Search(const string& s) {
        int cur = 0;
        for (char c: s) {
            int nxt = trie[cur][(int)c];
            if (nxt == -1) return {};
            cur = nxt;
        }
        return node_idx[cur];
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        words = sentences;
        n = words.size();
        
        int len = 0;
        for (int i=0; i<n; ++i) len += words[i].length();
        Init(10 * len);
        
        for (int i=0; i<n; ++i) {
            freq[words[i]] = times[i];
            Insert(words[i], i);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            if (freq.find(cur_query) != freq.end()) {
                freq[cur_query]++;
            } else {
                words.push_back(cur_query);
                Insert(cur_query, n);
                ++n;
                freq[cur_query] = 1;
            }
            cur_query = "";
            return {};
        }
        cur_query.push_back(c);
        vector<int> idxs = Search(cur_query);
        
        sort(begin(idxs), end(idxs), [&](int i, int j) {
            int fi = freq[words[i]], fj = freq[words[j]];
            if (fi != fj) return fi > fj;
            else return words[i] < words[j];
        });
        
        vector<string> res;
        int len = min(3, (int)idxs.size());
        for (int i = 0; i < len; ++i) {
            res.push_back(words[idxs[i]]);
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
