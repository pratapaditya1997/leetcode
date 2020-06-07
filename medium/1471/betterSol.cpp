using pii = pair<int, int>;

class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        int n = size(a);
        vector<int> ans;
        
        sort(begin(a), end(a));
        int med = a[(n-1)/2], l = 0, r = n-1, sz = 0;
        while(sz < k) {
            if(abs(a[l]-med) > abs(a[r]-med)) ans.push_back(a[l++]);
            else ans.push_back(a[r--]);
            ++sz;
        }
        return ans;
    }
};
