class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(i-1 >= 0 && (a[i] ^ a[i-1]) == 0) return a[i];
            if(i-2 >= 0 && (a[i] ^ a[i-2]) == 0) return a[i];
        }
        return a[n-1];
    }
};
