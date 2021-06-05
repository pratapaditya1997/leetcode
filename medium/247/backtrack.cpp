vector<char> cur{'0', '1', '8', '6', '9'};
vector<char> nxt{'0', '1', '8', '9', '6'};

vector<char> single{'0', '1', '8'};

class Solution {
public:
    vector<string> ans;
    
    void f(int l, int r, string& so_far) {
        if (l > r) {
            ans.push_back(so_far);
            return;
        }
        if (l == r) {
            for (int i=0; i<3; ++i) {
                so_far[l] = so_far[r] = single[i];
                f(l+1, r-1, so_far);
                so_far[l] = so_far[r] =  ' ';
            }
        } else {
            for (int i=0; i<5; ++i) {
                if (l == 0 && i == 0) continue;
                so_far[l] = cur[i];
                so_far[r] = nxt[i];
                f(l+1, r-1, so_far);
                so_far[l] = ' ';
                so_far[r] = ' ';
            }
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        ans.clear();
        string so_far(n, ' ');
        f(0, n-1, so_far);
        return ans;
    }
};
