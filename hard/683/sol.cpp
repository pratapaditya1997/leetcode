template <typename T>
class fenwick {
public:
    vector<T> bit;
    int n;
    
    fenwick(int _n): n(_n) {
        bit.resize(n);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            bit[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += bit[x];
            x = (x & (x+1)) - 1;
        }
        return v;
    }
    
    T getRange(int l, int r) {
        return get(r) - get(l-1);
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        fenwick<int> f(n+1);
        
        for (int i=0; i<n; i++) {
            int j = bulbs[i];
            f.modify(j, 1);
            
            if (j-k-1 > 0) {
                int prev_elem = f.getRange(j-k-1, j-k-1);
                int window_sum = f.getRange(j-k,j-1);
                if (prev_elem == 1 && window_sum == 0) return i+1;
            }
            
            if (j+k+1 <= n) {
                int next_elem = f.getRange(j+k+1, j+k+1);
                int window_sum = f.getRange(j+1,j+k);
                if (next_elem == 1 && window_sum == 0) return i+1;
            }
        }
        
        return -1;
    }
};
