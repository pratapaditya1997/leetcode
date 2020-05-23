class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int a_len = a.size();
        int b_len = b.size();

        if(a_len > b_len) {
            swap(a,b);
            swap(a_len, b_len);
        }

        int left_half_len = (a_len + b_len + 1)/2;

        int lo = 0, hi = a_len;
        while(lo <= hi) {
            int i = lo + ((hi - lo)/2);
            int j = left_half_len - i;

            if(i && a[i-1] > b[j]) {
                hi = i-1;
            } else if(i < a_len && b[j-1] > a[i]) {
                lo = i+1;
            } else {
                int x;
                if(i == 0) x = b[j-1];
                else if(j == 0) x = a[i-1];
                else x = max(a[i-1], b[j-1]);

                if((a_len + b_len)&1) return x;
                
                int y;
                if(i == a_len) y = b[j];
                else if(j == b_len) y = a[i];
                else y = min(a[i], b[j]);

                return (double)(x+y)/2.0;
            }
        }

        return -1;
    }
};