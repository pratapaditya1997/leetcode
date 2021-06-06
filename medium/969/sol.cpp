class Solution {
public:
    int GetIdx(vector<int>& v, int n) {
        for (int i=0; i<n; ++i) {
            if (v[i] == n) return i;
        }
        return 0;
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        vector<int> v = arr;
        
        int n = arr.size();
        for (int i=n; i>=1; --i) {
            int idx = GetIdx(v, i);
            ans.push_back(idx+1);
            reverse(v.begin(), v.begin() + idx + 1);
            ans.push_back(i);
            reverse(v.begin(), v.begin() + i);
        }
        
        return ans;
    }
};
