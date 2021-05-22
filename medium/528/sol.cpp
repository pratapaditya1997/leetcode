class Solution {
private:
    vector<int> pref;
    int sum;
    
public:
    Solution(vector<int>& w) {
        srand(time(0));
        int n = w.size();
        sum = 0;
        for (int i=0; i<n; i++) {
            pref.push_back(sum + w[i]);
            sum = pref.back();
        }
    }
    
    int pickIndex() {
        double perc = ((rand() % 100) + 1) / 100.0;
        int reqd = ceil(perc * sum * 1.0);
        int idx = lower_bound(pref.begin(), pref.end(), reqd) - pref.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
