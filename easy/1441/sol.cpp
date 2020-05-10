class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 0;
        for(int i=1; i<=n; i++) {
            ans.push_back("Push");
            if(target[cur] == i) {
                cur++;
                if(cur == target.size()) break;
            } else ans.push_back("Pop");
        }
        return ans;
    }
};
