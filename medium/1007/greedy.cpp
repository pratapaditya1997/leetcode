class Solution {
public:
    int check(int x, vector<int>& a, vector<int>& b, int n) {
        int ret_a = 0, ret_b = 0;
        for (int i=0; i<n; i++) {
            if (a[i] != x && b[i] != x) return -1;
            else if (a[i] != x) ret_a++;
            else if (b[i] != x) ret_b++;
        }
        return min(ret_a, ret_b);
    }
    
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int ans1 = check(a[0], a, b, n);
        int ans2 = check(b[0], a, b, n);
        if (ans1 == -1 && ans2 == -1) return -1;
        else if (ans1 == -1) return ans2;
        else if (ans2 == -1) return ans1;
        else return min(ans1, ans2);
    }
};
