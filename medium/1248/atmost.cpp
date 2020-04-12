class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
    
    int atmost(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, cur = 0, l = 0, r = 0;
        while(r<n) {
            cur += (arr[r]%2);
            while(cur > k) {
                cur -= (arr[l]%2);
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};
