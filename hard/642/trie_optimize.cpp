typedef pair<string, int> psi;

struct Comp {
    bool operator() (const psi& a, const psi& b) const {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

class AutocompleteSystem {
private:
    int n;
    unordered_map<string, int> freq;
    vector<string> words;
    string cur_query;
    priority_queue<psi, vector<psi>, Comp> pq;
    
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
        
        pq = priority_queue<psi, vector<psi>, Comp>();
        for (int idx: idxs) {
            pq.push({words[idx], freq[words[idx]]});
        }
        
        vector<string> res;
        for (int i=0; i<3 && !pq.empty(); ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
