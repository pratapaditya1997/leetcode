class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int _k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int num: nums) add(num);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
