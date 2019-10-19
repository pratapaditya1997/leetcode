class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = (int)a.size();
        int d = (a[n-1] - a[0])/n;
        
        for(int i=1;i<n;i++){
            if(a[i-1] + d != a[i]) return a[i-1]+d;
        }
        
        return a[n-1] + d;
    }
};
