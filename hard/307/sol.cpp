class NumArray {
public:
    int n;
    vector<int> t;
    
    void build(vector<int>& a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(a, v*2+1, tl, tm);
            build(a, v*2+2, tm+1, tr);
            t[v] = t[v*2+1] + t[v*2+2];
        }
    }
    
    int sum(int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if(l == tl && r == tr) return t[v];
        int tm = (tl+tr)/2;
        int left_sum =  sum(v*2+1, tl, tm, l, min(r, tm));
        int right_sum = sum(v*2+2, tm+1, tr, max(l, tm+1), r);
        return left_sum + right_sum;
    }
    
    void update(int v, int tl, int tr, int i, int val) {
        if(tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl+tr)/2;
            if(i <= tm) update(v*2+1, tl, tm, i, val);
            else update(v*2+2, tm+1, tr, i ,val);
            t[v] = t[v*2+1] + t[v*2+2];
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n == 0) return;
        t.assign(4*n, 0);
        build(nums, 0, 0, n-1);
    }
    
    void update(int i, int val) {
        update(0,0,n-1,i,val);
    }
    
    int sumRange(int i, int j) {
        return sum(0,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
