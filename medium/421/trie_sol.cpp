const int N = 3e6 + 6;
const int ALPHA = 2;

int trie[N][ALPHA];
int nodes;

void init() {
    nodes = 0;
    memset(trie, -1, sizeof trie);
}

int addEdge(int node, int bit) {
    int nxt = trie[node][bit];
    if (nxt == -1) {
        nxt = ++nodes;
        trie[node][bit] = nxt;
    }
    return nxt;
}

void insert(int num) {
    int cur = 0;
    for (int i = 30; i >= 0; i--) {
        bool bit = (1<<i)&num;
        cur = addEdge(cur, bit);
    }
}

int search(int num) {
    int ret = 0, cur = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (1<<i)&num;
        if (bit > 0) bit = 1;
        
        if (trie[cur][1 - bit] == -1) {
            cur = trie[cur][bit];
        } else {
            ret += (1<<i);
            cur = trie[cur][1 - bit];
        }
    }

    return ret;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        init();
    
        int ans = 0;
        for (int num: nums) insert(num);

        for (int num: nums) {
            ans = max(ans, search(num));
        }

        return ans;
    }
};
