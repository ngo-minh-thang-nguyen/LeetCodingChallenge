class RandomizedSet {
private:
    map<int, int> ourMap;
    vector<int> nums;
public:
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( ourMap.find(val) != ourMap.end() ) 
            return false;
        
        nums.push_back(val);
        ourMap[ val ] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( ourMap.find(val) != ourMap.end() ) {
            int last = nums.back();
            ourMap[last] = ourMap[val];
            nums[ ourMap[val] ] = last;
            nums.pop_back();
            ourMap.erase(val);
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randNum = rand() % nums.size();
        return nums[randNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
