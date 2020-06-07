using pii = pair<int, int>;

class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        int n = size(a);
        vector<pii> v;
        
        sort(a.begin(), a.end());
        int med = a[(n-1)/2];
        for(int i=0; i<n; i++) {
            v.push_back({abs(a[i]-med), a[i]});
        }
        
        sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
            if(a.first == b.first) return (a.second > b.second);
            return (a.first > b.first);
        });
        
        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(v[i].second);
        return ans;
    }
};
