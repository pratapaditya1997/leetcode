class Solution {
public:
    const long mod = 1e9+7;
    
    void add(long& a, long b) {
        a += b;
        if(a >= mod) a -= mod;
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long> cnt(101,0);
        for(int num: arr) cnt[num]++;
        
        long ans = 0;
        for(int i=0; i<101; i++) {
            if(3*i == target) add(ans, cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6);
            for(int j=i+1; j<101; j++) {
                int k = target-i-j;
                if(k < 0) break;
                if(i+2*j == target) add(ans, cnt[i]*cnt[j]*(cnt[j]-1)/2);
                else if(2*i+j == target) add(ans, cnt[i]*cnt[j]*(cnt[i]-1)/2);
                else {
                    if(k < 101 && k > j) add(ans, cnt[i]*cnt[j]*cnt[k]);
                }
            }
        }
        return ans%mod;
    }
};
