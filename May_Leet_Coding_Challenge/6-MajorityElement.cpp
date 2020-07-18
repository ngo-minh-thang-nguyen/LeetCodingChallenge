class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map between an int in nums and its frequency
        map <int, int> mapNumAndFrequency;
        
        // count frequencies
        for ( int i = 0; i < nums.size(); i++ ) {
            mapNumAndFrequency[ nums[i] ]++;
        }
        
        int threshold = nums.size()/2 + 1;
        
        // if an entry in mapNumAndFrequency has frequency more than threshold, return it
        for ( auto & entry : mapNumAndFrequency )
            if ( entry.second >= threshold ) return entry.first;
        
        return -1;
    }
};
