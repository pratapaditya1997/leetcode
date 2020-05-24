class Solution {
public:
    
    // checks if it is possible to have atleast(>=k) partitions with 'm'
    bool check(int m,vector<int>& a,int k) {
        int used = 0, n = (int)a.size(), sum = 0;
        for(int i=0;i<n;i++) {
            sum += a[i];
            if(sum >= m) {
                ++used;
                sum = 0;
            }
        }
        
        if(used < k+1) return false;
        return true;
    }
    
    int maximizeSweetness(vector<int>& a, int k) {
        int l = 0, h = 1000 * 1000 * 1000, ans = 0;
        
        while(l <= h) {
            int m = (l+h)/2;
            if(check(m,a,k)) {
                l = m+1;
                ans = m;
            } else h = m-1;
        }
        
        return ans;
    }
};
