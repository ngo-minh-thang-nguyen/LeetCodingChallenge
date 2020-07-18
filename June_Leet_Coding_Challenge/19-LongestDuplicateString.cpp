class Solution {
public:
    string longestDupSubstring(string S) {
        res = "";
        power = vector<int>( S.size(), 1 );
        int i;
        
        for ( i = 1 ; i < S.size(); i++ ) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        int low = 0;
        int high = S.size();
        
        while ( low <= high ) {
            int mid = low + (high - low) / 2;
            string tmp = validate( mid, S );
            if ( tmp.size() == 0 ) {
                high = mid - 1;
            } else {
                if ( tmp.size() > res.size() ) {
                    res = tmp;
                }
                low = mid + 1;
            }
        }
        
        return res;
    }
    
private:
    int prime = 19260817;
    string res;
    vector<int> power;
    string validate( int desire, string str ) {
        if ( desire == 0 ) 
            return "";
        unordered_map<int, vector<int>> hashmap = unordered_map<int, vector<int>>();
        long long current = 0;
        int i;
        
		// compute the hash value of the first "size" characters
        for (i = 0 ; i < desire; i++) {
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        }
        
        // store the result in a hashmap that maps from hashvalue to starting index
        hashmap[current] = vector<int>(1, 0);
        
        for (i = desire ; i < str.size(); i++) {
		    // sliding window to maintain the current substr's hashmap value
            current = ((current - (long long) power[desire - 1] * (str[i - desire] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;
            if (hashmap.find(current) == hashmap.end()) {
                hashmap[current] = vector<int>(1, i - desire + 1);
            } else {
                for ( auto it : hashmap[current] ) {
                    
                    if (strcmp((str.substr(it, desire)).data(), str.substr(i - desire + 1, desire).data()) == 0) {
                        return str.substr(it, desire);
                    }
                }
                
                hashmap[current].push_back(i - desire + 1);
            }
        }
        
        return "";
    }
};
