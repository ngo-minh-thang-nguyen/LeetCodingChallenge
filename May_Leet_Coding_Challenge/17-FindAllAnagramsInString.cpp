class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if ( s.size() < p.size() )
            return result;
        else {
            int originalArray [26] = {0};
            int ourArray [26] = {0};
            
            for ( int i = 0; i < p.size(); i++ )
                originalArray[ p[i] - 'a' ]++;
            
            for ( int i = 0; i <= s.size(); i++ ) {
                if ( i >= p.size() ) {
                    if ( compareTwoArrays( originalArray, ourArray ) ) 
                        result.push_back( i - p.size() );
                    
                    if ( i >= s.size() ) 
                        break;
                    
                    ourArray[ s[ i-p.size() ]-'a' ]--;
                    ourArray[ s[i]-'a' ]++;
                }
                else {
                    ourArray[ s[i] - 'a' ]++;
                }
            }
            
            return result;
        }
    }
        
    bool compareTwoArrays( int originalArray[26], int ourArray[26] )
    {
        for ( int i = 0; i < 26; i++ ) {
            if ( originalArray[i] != ourArray[i] )
                return 0;
        }

        return 1;
    }
};
