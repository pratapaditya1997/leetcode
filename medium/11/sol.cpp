class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size(), best = 0;
        int leftPointer = 0, rightPointer = n-1;
        
        while(leftPointer != rightPointer) {
            int val = min(height[leftPointer], height[rightPointer]);
            best = max(best, (rightPointer - leftPointer)*val);
            if(height[leftPointer] <= height[rightPointer]) {
                leftPointer++;
            } else rightPointer--;
        }
        
        return best;
    }
};
