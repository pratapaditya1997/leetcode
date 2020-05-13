using pii = pair<int,int>;

class Solution {
public:
    struct comp {
        bool operator()(pii& p, pii& q) {
            return p.first > q.first;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        int n = a.size();
        vector<pii> vals;
        
        for(int i=0; i<n; i++) {
            vals.push_back({a[i][0]*a[i][0]+a[i][1]*a[i][1], i});
        }
        priority_queue<pii, vector<pii>, comp> pq(vals.begin(), vals.end());
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(a[idx]);
        }
        return ans;
    }
};
