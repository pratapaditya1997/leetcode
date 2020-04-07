class Solution {
public:
    int mod = 1e9+7;
    
    int add(int a, int b) {
        a += b;
        if(a >= mod) a -= mod;
        return a;
    }
    
    int mul(long long int a,long long int b){
        long long int c = (a%mod) * (b%mod);
        return c%mod;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size(), best=0, cur=0;
        for(int i=0; i<n; i++) {
            cur += arr[i];
            if(cur >= best) best = cur;
            if(cur < 0) cur=0;
        }
        if(k==1) return best;
        
        int maxPref=0, maxSuff=0;
        cur = 0;
        for(int i=0; i<n; i++) {
            cur += arr[i];
            maxPref = max(maxPref, cur);
        }
        cur = 0;
        for(int i=n-1; i>=0; i--) {
            cur += arr[i];
            maxSuff = max(maxSuff, cur);
        }
        
        int total = accumulate(arr.begin(), arr.end(), 0);
        int val = add(add(maxPref,mul(k-2,total)),maxSuff);
        return max({best, val, maxPref+maxSuff});
    }
};
