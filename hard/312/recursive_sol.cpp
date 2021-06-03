class Solution {
public:
    vector<vector<int>> dp;
    
    /*
    * returns max value for the interval (l,r) i.e. l and r are not included
    */
    int f(int l, int r, vector<int>& a) {
        if (l+1 == r) return 0;
        
        int& ret = dp[l][r];
        if (ret != -1) return ret;
        
        ret = 0;
        // choose value between [l+1, r-1] as l and r are not included
        for (int i=l+1; i<r; ++i) {
            ret = max(ret, a[l]*a[i]*a[r] + f(l, i, a) + f(i, r, a));
        }
        return ret;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> a; // new array of balloon values with the padding at both ends
        
        a.push_back(1);
        for (int num: nums) {
            if (num > 0) a.push_back(num); // remove 0 value balloons, they anyway contribute 0 to the answer
        }
        a.push_back(1);
        
        int n = a.size();
        dp = vector<vector<int>> (n, vector<int>(n, -1));
        return f(0, n-1, a);
    }
};
