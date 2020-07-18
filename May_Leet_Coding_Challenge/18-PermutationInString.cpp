class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool result;
        if ( s1.size() > s2.size() )
            return false;
        else {
            int arrayS1 [26] = {0};
            int arrayS2 [26] = {0};
            
            for ( int i = 0; i < s1.size(); i++ )
                arrayS1[ s1[i] - 'a' ]++;
            
            for ( int i = 0; i <= s2.size(); i++ ) {
                if ( i >= s1.size() ) {
                    if ( compareTwoArrays( arrayS1, arrayS2 ) ) 
                        return true;
                    
                    if ( i >= s2.size() ) 
                        break;
                    
                    arrayS2[ s2[ i-s1.size() ]-'a' ]--;
                    arrayS2[ s2[i]-'a' ]++;
                }
                else {
                    arrayS2[ s2[i] - 'a' ]++;
                }
            }
            
            return false;
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
