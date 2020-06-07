class BrowserHistory {
public:
    vector<string> history;
    int sz,cur;
        
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        sz = cur = 0;
    }
    
    void visit(string url) {
        if(cur == sz) {
            if(sz == history.size()-1) history.push_back(url);  
            else history[cur+1] = url;
            ++sz; ++cur;
        } else {
            history[cur+1] = url;
            ++cur;
            sz = cur;
        }
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min(cur+steps, sz);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
