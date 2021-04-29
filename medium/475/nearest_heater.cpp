class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        
        vector<int> nearest(houses.size(), INT_MAX);
        
        // calculate distance to nearest RHS heater
        for (int i = 0, j = 0; i < houses.size() && j < heaters.size();) {
            if (houses[i] <= heaters[j]) {
                nearest[i] = heaters[j] - houses[i];
                i++;
            } else j++;
        }
        
        // calculate distance to nearest LHS heater
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0;) {
            if (houses[i] >= heaters[j]) {
                nearest[i] = min(nearest[i], houses[i] - heaters[j]);
                i--;
            } else j--;
        }
        
        return *max_element(nearest.begin(), nearest.end());
    }
};
