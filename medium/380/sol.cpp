class RandomizedSet {
public:
    vector<int> nums;
    map<int,int> lookup;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(lookup.find(val) != lookup.end()) return false;
        nums.push_back(val);
        lookup[val] = (int)nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(lookup.find(val) == lookup.end()) return false;
        int idx = lookup[val];
        int len = (int)nums.size();
        lookup[nums[len-1]] = idx;
        lookup.erase(val);
        swap(nums[idx], nums[len-1]);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int len = (int)nums.size();
        return nums[rand() % len];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
