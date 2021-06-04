class Solution {
public:
    char Prev(char c) {
        int x = c - '0';
        x = (x - 1 + 10) % 10;
        return char(x + '0');
    }
    
    char Next(char c) {
        int x = c - '0';
        x = (x + 1) % 10;
        return char(x + '0');
    }
    
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        
        set<string> dead_ends(deadends.begin(), deadends.end());
        unordered_map<string, int> dist;
        
        if (dead_ends.find("0000") != dead_ends.end()) return -1;
        
        queue<string> q;
        q.push("0000");
        dist["0000"] = 0;
        
        string temp;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            
            for (int i=0; i<4; ++i) {
                temp = cur;
                temp[i] = Prev(cur[i]);
                if (dist.find(temp) != dist.end() || dead_ends.find(temp) != dead_ends.end()) continue;
                dist[temp] = dist[cur] + 1;
                if (temp == target) return dist[temp];
                q.push(temp);
            }
            
            for (int i=0; i<4; ++i) {
                temp = cur;
                temp[i] = Next(cur[i]);
                if (dist.find(temp) != dist.end() || dead_ends.find(temp) != dead_ends.end()) continue;
                dist[temp] = dist[cur] + 1;
                if (temp == target) return dist[temp];
                q.push(temp);
            }
        }
        
        return -1;
    }
};
