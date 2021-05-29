typedef long long int ll;
typedef pair<int, int> pii;

struct Task {
    int id, arrival, processing;
    
    bool operator < (const Task& other) const {
        return make_tuple(arrival, processing, id) < make_tuple(other.arrival, other.processing, other.id);
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<Task> v(n);
        for (int i=0; i<n; ++i) {
            Task t{i, tasks[i][0], tasks[i][1]};
            v[i] = t;
        }
        
        sort(v.begin(), v.end());
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> ans;
        
        ll cur_time = v[0].arrival;
        int i = 0;
        while (i < n) {
            while (i < n && v[i].arrival <= cur_time) {
                pq.push({v[i].processing, v[i].id});
                ++i;
            }
            if (pq.empty()) {
                cur_time = v[i].arrival;
            } else {
                pii p = pq.top(); pq.pop();
                cur_time += p.first;
                ans.push_back(p.second);
            }
        }
        
        while (!pq.empty()) {
            pii p = pq.top(); pq.pop();
            cur_time += p.first;
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
