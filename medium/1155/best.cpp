class Solution {
public:
    int mod = 1e9+7;
    
    void add(int& a, int b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    void sub(int& a, int b) {
        a -= b;
        if(a<0) a += mod;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        vector<int> prevDp(target+1,0), curDp(target+1,0);
        prevDp[0] = 1;
        for(int i=1; i<=d; i++) {
            int cur = 0;
            for(int j=1; j<=target; j++) {
                add(cur,prevDp[j-1]);
                if(j>f)  sub(cur,prevDp[j-f-1]);
                curDp[j] = cur;
            }
            for(int j=0; j<=target; j++) {
                prevDp[j] = curDp[j];
                curDp[j] = 0;
            }
        }
        return prevDp[target];
    }
};
