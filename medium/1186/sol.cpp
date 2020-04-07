class Solution {
public:
    int kadane(vector<int>& arr) {
        int best=INT_MIN, cur=0;
        for(int x: arr) {
            cur += x;
            best = max(best, cur);
            if(cur < 0) cur = 0;
        }
        return best;
    }
    
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n), suf(n);
        pre[0] = arr[0]; suf[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++) pre[i] = max(pre[i-1]+arr[i], arr[i]);
        for(int i=n-2; i>=0; i--) suf[i] = max(suf[i+1]+arr[i], arr[i]);
        
        int best = kadane(arr), cur = INT_MIN;
        for(int i=0;i<n;i++) {
            cur = INT_MIN;
            if(i>0) cur = pre[i-1];
            if(i != n-1) {
                if(cur == INT_MIN) cur = suf[i+1];
                else cur += suf[i+1];
            }
            best = max(best, cur);
        }
        return best;
    }
};
