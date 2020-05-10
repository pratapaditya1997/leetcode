class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        
        vector<int> pre(n+1,0);
        for(int i=1; i<=n; i++) {
            pre[i] = pre[i-1] ^ arr[i-1];
        }
        
        for(int i=0; i<n; i++) {
            for(int k=i+1; k<n; k++) {
                if((pre[k+1]^pre[i]) == 0) ans += (k-i);
            }
        }
        return ans;
    }
};
