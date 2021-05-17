const double PI = 3.14159265;

class Solution {
public:
    double radianToDegree(double radian) {
        return (radian * 180.0) / PI;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int m = 0;
        vector<vector<int>> p;
        
        for (auto& point: points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                m++;
            } else p.push_back(point);
        }
        
        int n = p.size();
        vector<double> thetas(n);
        
        int x = location[0], y = location[1];
        for (int i=0; i<n; i++) {
            int x1 = p[i][0], y1 = p[i][1];
            thetas[i] = radianToDegree(atan2(y1 - y, x1 - x));
            if (thetas[i] < 0) thetas[i] += 360.0;
        }
        sort(thetas.begin(), thetas.end());
        
        vector<double> dup = thetas;
        thetas.insert(thetas.end(), dup.begin(), dup.end());
        for (int i=n; i<thetas.size(); i++) thetas[i] += 360.0;
        
        n = 2*n;
        int l = 0, ans = 0;
        for (int r=0; r<n; r++) {
            while((thetas[r] - thetas[l]) > angle) l++;
            ans = max(ans, r-l+1);
        }
        
        return ans + m;
    }
};
