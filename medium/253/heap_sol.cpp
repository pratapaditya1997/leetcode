class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] <= b[0];
        });
        
        min_heap.push(arr[0][1]);
        for (int i=1; i<n; i++) {
            if (arr[i][0] >= min_heap.top()) {
                // room is free so assign it to current meeting
                min_heap.pop();
            }
            // no room is free, so assign new room to current meeting
            min_heap.push(arr[i][1]);
        }
        
        return min_heap.size();
    }
};
