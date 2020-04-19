const int N = 26;
vector<int> g[N];

class Solution {
public:
    vector<int> color;
    
    void dfs(int u, int c) {
        color[u] = c;
        for(int v: g[u]) {
            if(color[v] == 0) dfs(v,c);
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<N; i++) g[i].clear();
        
        for(string str: equations) {
            int u = str[0]-'a', v = str[3]-'a';
            if(str[1] == '=') {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        
        color.assign(26, 0);
        for(int i=0; i<26; i++) {
            if(color[i] == 0 && g[i].size() > 0) {
                dfs(i, i+1);
            }
        }
        
        for(string str: equations) {
            int u = str[0]-'a', v = str[3]-'a';
            if(str[1] == '!') {
                if(u == v) return false;
                if(color[u] == color[v] && color[u] != 0) return false;
            }
        }
        return true;
    }
};
