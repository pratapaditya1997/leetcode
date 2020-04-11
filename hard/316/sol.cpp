class Solution {
public:
    string removeDuplicateLetters(string text) {
        string ans = "";
        vector<int> used(26,0), count(26,0);
        
        for(char c: text) count[c-'a']++;
        for(char c: text) {
            --count[c-'a'];
            if(used[c-'a']) continue;
            while(!ans.empty() && ans.back() > c && count[ans.back()-'a']) {
                used[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c-'a'] = 1;
        }
        return ans;
    }
};
