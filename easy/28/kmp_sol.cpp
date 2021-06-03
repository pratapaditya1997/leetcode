typedef long long int ll;

const int p = 31;
const int m = 1e9 + 9;

class Solution {
public:
    int strStr(string t, string s) {
        string str = s + "#" + t;
        int n = str.length(), req = s.length();
        
        if (req == 0) return 0;
        
        vector<int> pi(n, 0);
        for (int i=1; i<n; ++i) {
            int j = pi[i-1];
            while (j > 0 && str[i] != str[j]) {
                j = pi[j-1];
            }
            if (str[i] == str[j]) ++j;
            pi[i] = j;
            
            if (j == req && i >= req) return i - 2*req;
        }
        
        return -1;
    }
};
