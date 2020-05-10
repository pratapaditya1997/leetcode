class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        dequeue<int> max_q, min_q;
        int l=0, res=1;
        for(int r=0; r<nums.size(); r++) {
            while(!max_q.empty() && max_q.back() < nums[r]) max_q.pop_back();
            while(!min_q.empty() && min_q.back() > nums[r]) min_q.pop_back();
            max_q.push_back(nums[r]);
            min_q.push_back(nums[r]);
            while(max_q.front() - min_q.front() > limit) {
                if(max_q.front() == nums[l]) max_q.pop_front();
                if(min_q.front() == nums[l]) min_q.pop_front();
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};