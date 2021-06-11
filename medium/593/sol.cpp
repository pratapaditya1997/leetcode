typedef pair<int, int> pii;

class Solution {
public:
    int dist(pii a, pii b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
    
    bool AllEqual(vector<int> v) {
        int n = v.size();
        for (int i=0; i<n-1; ++i) {
            if (v[i] != v[i+1] || v[i] == 0) return false;
        }
        return true;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pii> v {{p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
        sort(v.begin(), v.end());
        
        vector<int> sides(4);
        sides[0] = dist(v[0], v[1]);
        sides[1] = dist(v[1], v[3]);
        sides[2] = dist(v[3], v[2]);
        sides[3] = dist(v[0], v[2]);
        
        if (!AllEqual(sides)) return false;
        
        vector<int> diag(2);
        diag[0] = dist(v[1], v[2]);
        diag[1] = dist(v[0], v[3]);
        
        if (!AllEqual(diag)) return false;
        
        return true;
    }
};
