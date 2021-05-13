const int DELTA = 1e4 + 4;
const int N = 2 * DELTA;

class fenwick {
public:
    vector<int> bit;
    int n;
    
    fenwick(int _n): n(_n) {
        bit.resize(n);
    }
    
    void modify(int x, int v) {
        while(x < n) {
            bit[x] += v;
            x |= (x+1);
        }
    }
    
    int get(int x) {
        int v = 0;
        while(x >= 0) {
            v += bit[x];
            x = (x & (x+1)) - 1;
        }
        return v;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        for (int& num: nums) num += DELTA;
        
        fenwick f(N);
        int n = nums.size();
        
        vector<int> ans(n, 0);
        for (int i=n-1; i>=0; i--) {
            f.modify(nums[i], 1);
            ans[i] = f.get(nums[i] - 1);
        }
        
        return ans;
    }
};
