class Solution {
public:
    string s;
    int dp[10][2][2][2][1<<11];

    int f(int i, int tight, int st, bool flag, int mask) {
        if(i == s.length()) return flag>0 ? 1 : 0;
        if(dp[i][tight][st][flag][mask] != -1) {
            return dp[i][tight][st][flag][mask];
        }
        int res = 0, new_tight = tight;
        int lim = tight ? s[i]-'0' : 9;

        if(!st) {
            res = f(i+1, tight & s[i]=='0', st, flag, mask);
            for(int d=1; d<=lim; d++) {
                res += f(i+1, tight & d==lim, 1, flag, mask|(1<<d));
            }
        } else {
            for(int d=0; d<=lim; d++) {
                res += f(i+1, tight & d==lim, 1, flag|(mask&(1<<d)), mask|(1<<d));
            }
        }
        return dp[i][tight][st][flag][mask] = res;
    }

    int numDupDigitsAtMostN(int N) {
        s = to_string(N);
        memset(dp,-1,sizeof dp);
        return f(0,1,0,0,0); 
    }
};
