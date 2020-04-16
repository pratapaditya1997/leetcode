class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
        vector<int> ans;
        int cur_level = findLevel(n);
        while(n != 1) {
            ans.push_back(n);
            int start_level = startLevel(cur_level);
            int par_offset = (n - start_level)/2;
            n = getFromLast(cur_level - 1, par_offset);
            cur_level -= 1;
        }
        ans.push_back(n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int findLevel(int n) {
        int ret = 0;
        while(n) {
            ret++;
            n /= 2;
        }
        return ret;
    }
    
    int startLevel(int level) {
        return 1<<(level-1);
    }
    
    int lastLevel(int level) {
        return (1<<(level)) - 1;
    }
    
    int getFromLast(int level, int offset) {
        int last = lastLevel(level);
        return last - offset;
    }
};
