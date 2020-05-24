class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& s1, vector<vector<int>>& s2, int dur) {
        sort(s1.begin(), s1.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        sort(s2.begin(), s2.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int n = (int)s1.size(), m = (int)s2.size();
        vector<int> res;
        for(int i = 0, j = 0; i < n && j < m;) {
            int x = max(s1[i][0], s2[j][0]);
            int y = min(s1[i][1], s2[j][1]);
            
            if(y - x >= dur) {
                res = {x, x + dur};
                return res;
            }
            if(s1[i][0] < s2[j][0]) i++;
            else j++;
        }
        
        return res;
    }
};
