vector<int> limit{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> ans;

int n;
string s;

class Solution {
public:
    void f(int idx, vector<int>& used, string& cur) {
        if (idx == n) {
            ans.push_back(cur);
            return;
        }
        
        int num = s[idx]-'0';
        int lim = limit[num];
        for (int i=0; i<lim; ++i) {
            // check if ith bit of used[idx] is set or not
            if (used[idx] & (1<<i)) {
                // used this bit, do nothing
            } else {
                // unused bit, use this char and set this bit
                int temp = used[idx];
                
                // setting things for next recursive call
                used[idx] |= (1<<i);            // set ith bit temporarily
                cur.push_back(letters[num][i]); // use the ith letter of the current digit
                
                // the next recursive call
                f(idx+1, used, cur);            // recurse to the next state
                
                // clearing the above things
                used[idx] = temp;               // unset the ith bit
                cur.pop_back();                 // remove the ith letter of current digit
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        s = digits;
        
        ans.clear();
        if (n == 0) return ans;
        
        vector<int> used(n, 0);
        string cur = "";
        f(0, used, cur);
        return ans;
    }
};
