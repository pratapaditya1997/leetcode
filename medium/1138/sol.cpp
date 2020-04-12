class Solution {
public:
    string alphabetBoardPath(string target) {
        int curX=0, curY=0;
        string ans = "";
        for(char c: target) {
            int nextX = (c-'a')/5, nextY = (c-'a')%5;
            ans += string(max(curX-nextX,0),'U') + string(max(curY-nextY,0),'L') + string(max(nextY-curY,0),'R') + string(max(nextX-curX,0),'D') + '!';
            curX = nextX;
            curY = nextY;
        }
        return ans;
    }
};
