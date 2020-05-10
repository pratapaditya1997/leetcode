class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> cur(mat[0]);
        for(int i=1; i<mat.size(); i++) {
            vector<int> n_row;
            for(int j=0; j<mat[i].size(); j++) {
                for(int v: cur) n_row.push_back(mat[i][j]+v);
            }
            sort(n_row.begin(), n_row.end());
            n_row.resize(min(k, (int)n_row.size()));
            swap(cur,n_row);
        }
        return cur[k-1];
    }
};