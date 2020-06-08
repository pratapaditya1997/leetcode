class Trie {
private:
    Trie* next[26] = {};
    int ends_here = 0;

public:
    Trie() {} // constructor
    ~Trie() {} // destructor

    void insert(string word) {
        Trie* node = this;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!node->next[idx]) {
                node->next[idx] = new Trie();
            }
            node = node->next[idx];
        }
        node->ends_here += 1;
    }

    bool search(string word) {
        Trie* node = this;
        for(char ch: word) {
            int idx = ch - 'a';
            if(!node->next[idx]) return false;
            node = node->next[idx];
        }
        return node->ends_here;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch: prefix) {
            int idx = ch - 'a';
            if(!node->next[idx]) return false;
            node = node->next[idx];
        }
        return true;
    }
};