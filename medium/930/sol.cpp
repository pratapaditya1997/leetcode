class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int sum) {
        return atmost(arr,sum) - atmost(arr,sum-1);
    }
    
    int atmost(vector<int>& arr, int k) {
        if(k < 0) return 0;
        int n = arr.size();
        int l=0, r=0, cur=0, ans=0;
        while(r<n) {
            cur += arr[r];
            while(cur > k) {
                cur -= arr[l];
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
};
