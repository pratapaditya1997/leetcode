class Logger {
    unordered_map<string, int> curr; // holds msgs in last 10s from init_time
    unordered_map<string, int> prev; // holds msgs in last 10s before init_time
    int init_time = 0;
public:
    /** Initialize your data structure here. */
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp >= init_time + 10) {
            // housekeeping stuff when curr map has been invalidated
            init_time = timestamp;
            prev = curr;
            curr.clear();
        }
        if (curr.find(message) != curr.end()) return false;
        if (prev.find(message) != prev.end() && prev[message] + 10 > timestamp) return false;
        curr[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
