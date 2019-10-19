class Solution {
    public List<Integer> minAvailableDuration(int[][] s1, int[][] s2, int dur) {
        Arrays.sort(s1, (a,b) -> a[0] - b[0]);
        Arrays.sort(s2, (a,b) -> a[0] - b[0]);
        
        int n = s1.length, m = s2.length;
        for(int i = 0,j = 0; i < n && j < m;) {
            int x = Math.max(s1[i][0], s2[j][0]);
            int y = Math.min(s1[i][1], s2[j][1]);
            
            if(y - x >= dur) {
                return Arrays.asList(x, x + dur);
            }
            if(s1[i][0] < s2[j][0]) i++;
            else j++;
        }
        
        return new ArrayList<>();
    }
}
