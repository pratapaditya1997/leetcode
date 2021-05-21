class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c: tasks) freq[c - 'A']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        int idle = (freq[0] - 1) * n;
        for (int i=1; i<26; i++) {
            int f = freq[i];
            idle -= min(freq[0] - 1, f);
            if (idle < 0) {
                idle = 0;
                break;
            }
        }
        
        return idle + tasks.size();
    }
};
