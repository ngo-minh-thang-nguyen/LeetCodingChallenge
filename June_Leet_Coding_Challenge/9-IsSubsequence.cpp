class Solution {
public:
    bool isSubsequence(string s, string t) {
        if ( s.size() > t.size() )
            return false;
        
        int i = 0, j = 0;
        for ( ; i < s.size(); i++ ) {
            char actualLetter = s[i];
            
            while ( j < t.size() ) {
                if ( t[j] == actualLetter ) {
                    if ( i == s.size() - 1  )
                        return true;
                    else {
                        j++;
                        break;
                    }
                }
                
                j++;
            }
                
            if ( j == t.size() ) {
                return false;
            }
        }
        
        return true;
    }
};
