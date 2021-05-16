class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        
        stack<int> s;
        for (int i=0; i<n; i++) {
            s.push(pushed[i]);
            while(j < n && !s.empty() && s.top() == popped[j]) {
                j++;
                s.pop();
            }
        }
        
        return (j == n);
    }
};
