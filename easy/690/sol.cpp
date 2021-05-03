/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

const int N = 2005;

vector<int> g[N];

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        for (int i=0; i<N; i++) g[i].clear();
        unordered_map<int, int> imp;
        
        for (auto& e: emp) {
            int u = e->id;
            imp[u] = e->importance;
            for (int v: e->subordinates) {
                g[u].push_back(v);
            }
        }
        
        function<int(int)> dfs = [&] (int u) {
            int ret = imp[u];
            for (int v: g[u]) ret += dfs(v);
            return ret;
        };
        
        return dfs(id);
    }
};
