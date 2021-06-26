vector<vector<int>> ans;
int n;

void Dfs(int v, vector<int>& cur, vector<vector<int>>& g) {
    if (v == n-1) {
        ans.push_back(cur);
        return;
    }
    
    for (int to: g[v]) {
        cur.push_back(to);
        Dfs(to, cur, g);
        cur.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size();
        vector<int> cur {0};
        
        ans.clear();
        Dfs(0, cur, g);
        return ans;
    }
};
