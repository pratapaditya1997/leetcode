class Solution {
public:

    template<typename iter>
    bool _next_permutation(iter begin, iter end) {
        // 0 element only
        if(begin == end) return false;
        
        // 1 element only
        iter i = begin;
        ++i;
        if(i == end) return false;

        // init iterator i as last element of container
        i = end;
        --i;

        while(true) {
            iter j = i;
            --i;

            if(*i < *j) {
                iter k = end;
                while(!(*i < *--k));
                iter_swap(i, k);
                reverse(j, end);
                return true;
            }

            if(i == begin) {
                reverse(begin, end);
                return false;
            }
        }
    }

    void nextPermutation(vector<int>& a) {
        _next_permutation(a.begin(), a.end());
        return;
    }
};