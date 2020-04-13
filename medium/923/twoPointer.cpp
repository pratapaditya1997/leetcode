class Solution {
public:
    const int mod = 1e9+7;
    
    void add(int& a,int b) {
        a += b;
        if(a >= mod) a-=mod;
    }
    
    int mul(int a, int b) {
        a %= mod; b %= mod;
        a *= b;
        return (a %= mod);
    }
    
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                int sum = arr[i] + arr[l] + arr[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else {
                    if(arr[l] != arr[r]) {
                        int left=1, right=1;
                        while(l+1 < r && arr[l]==arr[l+1]) {
                            left++;
                            l++;
                        }
                        while(r-1 > l && arr[r]==arr[r-1]) {
                            right++;
                            r--;
                        }
                        add(ans,mul(left,right));
                        l++;
                        r--;
                    } else {
                        add(ans,mul(r-l+1,r-l)/2);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
