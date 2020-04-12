class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, zeroCount = 0, left = 0;
        for(int right=0; right<n; right++) {
            if(arr[right] == 0) zeroCount++;
            while(zeroCount > k) {
                if(arr[left] == 0) zeroCount--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
