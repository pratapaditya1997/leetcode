struct Server {
    int idx, wt, cur_time;
};

struct CompareAvailableServer {
public:
    bool operator () (const Server& a, const Server& b) const {
        return make_tuple(a.wt, a.idx) > make_tuple(b.wt, b.idx);
    }
};

struct CompareUnavailableServer {
public:
    bool operator () (const Server& a, const Server& b) const {
        return make_tuple(a.cur_time, a.wt, a.idx) > make_tuple(b.cur_time, b.wt, b.idx);
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        
        priority_queue<Server, vector<Server>, CompareAvailableServer> available;
        priority_queue<Server, vector<Server>, CompareUnavailableServer> unavailable;
        
        for (int i=0; i<n; ++i) {
            Server s{i, servers[i], 0}; 
            available.push(s);
        }
        
        int m = tasks.size();
        vector<int> ans(m);
        
        int cur_time = 0, i = 0;
        while (i<m) {
            cur_time = max(cur_time, i);
            
            // add from unavailable to available
            while (1) {
                if (unavailable.empty()) break;
                auto s = unavailable.top();
                if (s.cur_time <= cur_time) {
                    unavailable.pop();
                    available.push(s);
                } else break;
            }
            
            // if available is empty, advance cur_time to least of unavailable set and add it to available
            if (available.empty()) {
                auto s = unavailable.top();
                unavailable.pop();
                cur_time = s.cur_time;
                available.push(s);
            }
            
            // find server from available list
            auto s = available.top();
            available.pop();
            ans[i] = s.idx;
            s.cur_time = cur_time + tasks[i];
            
            // add it to unavailable list
            unavailable.push(s);
            ++i;
        }
        
        return ans;
    }
};
