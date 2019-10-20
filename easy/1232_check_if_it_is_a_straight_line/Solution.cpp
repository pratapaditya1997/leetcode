class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& pts) {
        int n = (int)pts.size();
        
        sort(pts.begin(),pts.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int dy = pts[1][1] - pts[0][1];
        int dx = pts[1][0] - pts[0][0];
        int g = __gcd(dx,dy);
        dx /= g;
        dy /= g;
        
        for(int i=2;i<n;i++) {
            int tempDy = pts[i][1] - pts[i-1][1];
            int tempDx = pts[i][0] - pts[i-1][0];
            
            int g = __gcd(tempDy,tempDx);
            tempDx /= g;
            tempDy /= g;
            
            if(dy != tempDy || dx != tempDx) return false;
        }
        
        return true;
    }
};
