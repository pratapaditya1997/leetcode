typedef pair<int,int> pii;

class MyCalendar {
private:
    set<pii> s;
public:
    MyCalendar() {}
    
    bool book(int l, int r) {
        auto it = s.lower_bound({l, r});                         // return equivalent or next greater interval
        if (it != s.end() && it->first < r) return false;        // [l..r] [x..y] && x < r overlap
        if (it != s.begin() && (--it)->second > l) return false; // [x..y] [l..r] && y > l overlap
        s.insert({l, r});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
