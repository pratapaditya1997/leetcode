class Solution {
public:
    string squeeze(string s) {
        string ans = "";
        for(char c: s) if(c != ' ') ans += c;
        return ans;
    }
    
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> idx;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                idx.push(i);
            } else if(s[i] == ')') {
                if(idx.empty()) s[i]=' ';
                else idx.pop();
            }
        }
        
        while(!idx.empty()) {
            s[idx.top()] = ' ';
            idx.pop();
        }
        return squeeze(s);
    }
};
