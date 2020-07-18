class Solution {
public:
    int firstUniqChar(string s) {
        // create map to store frequency of chars in s
        map<char, int> mapCharAndFrequency;
        
        for ( int i = 0; i < s.size(); i++ ) {
            mapCharAndFrequency[ s[i] ]++;
        }
        
        // first char unique
        char firstCharUnique;
        
        // find first char unique in string s
        for ( int i = 0; i < s.size(); i++ ) {
            if ( mapCharAndFrequency[ s[i] ] == 1 ) {
                firstCharUnique = s[i];
                break;
            }
        }
        
        // return index of first char unique
        for ( int i = 0; i < s.size(); i++ ) {
            if ( firstCharUnique == s[i] )
                return i;
        }
        
        return -1;
    }
};
