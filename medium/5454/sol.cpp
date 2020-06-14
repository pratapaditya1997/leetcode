class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> cnt;
        for(int i: arr) cnt[i]++;
        
        vector<int> v;
        for(auto [key,val]: cnt) {
            v.emplace_back(val);
        }
        sort(begin(v), end(v));
        
        int ans = size(v), n = size(v);
        for(int i=0; i<n && k>0; i++) {
            k -= v[i];
            if(k>=0) ans--;
        }
        return ans;
    }
};
