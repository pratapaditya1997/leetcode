class Solution {
public:    
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> order;
        
        int n = mat.size();
        if(n == 0) return order;
        int m = mat[0].size();
        
        int up=0, down=n-1, left=0, right=m-1;
        while(up <= down && left <= right) {
            for(int col = left; col <= right; col++) order.push_back(mat[up][col]);
            for(int row = up+1; row <= down; row++) order.push_back(mat[row][right]);
            if(up < down && left < right) {
                for(int col = right-1; col > left; col--) order.push_back(mat[down][col]);
                for(int row = down; row > up; row--) order.push_back(mat[row][left]);
            }
            up++;
            down--;
            left++;
            right--;
        }
        
        return order;
    }
};
