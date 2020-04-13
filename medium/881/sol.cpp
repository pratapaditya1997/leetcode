class Solution {
public:
    int numRescueBoats(vector<int>& arr, int lim) {
        int n = arr.size(), ans = 0;
        int l=0, r=n-1;
        
        sort(arr.begin(), arr.end());
        while(l <= r) {
            ans++;
            if(arr[l] + arr[r] <= lim) l++;
            r--;
        }
        return ans;
    }
};
