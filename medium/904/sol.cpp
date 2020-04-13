class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size(), ans = 0, l = 0;
        unordered_map<int,int> count;
        for(int r=0; r<n; r++) {
            count[tree[r]]++;
            while(count.size() > 2) {
                if(count[tree[l]] == 1) {
                    count.erase(tree[l]);
                } else count[tree[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
