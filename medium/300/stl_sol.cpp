class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> res;
        for (int num: a) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end()) res.push_back(num);
            else *it = num;
        }
        return res.size();
    }
};
