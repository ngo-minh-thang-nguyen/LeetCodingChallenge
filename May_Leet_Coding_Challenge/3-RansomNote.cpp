class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // create maps to respectively count frequency of chars in ransomNote and magazine
        map <char, int> mapInNote;
        map <char, int> mapInMagazine;
        
        // count frequency of all chars in ransomNote
        for ( int i = 0; i < ransomNote.size(); i++ ) {
            mapInNote[ ransomNote[i] ] += 1; 
        }
        
        // count frequency of all chars in magazine
        for ( int i = 0; i < magazine.size(); i++ ) {
            mapInMagazine[ magazine[i] ] += 1; 
        }
        
        // verify if we can construct ransomNote from magazine
        for ( auto & entry : mapInNote ){
            // whenever we have a char in ransomNote whose frequency is strictly greater than 
            // its frequency in magazine, return false
            if ( entry.second > mapInMagazine[ entry.first ] ) return false;
        }
        
        return true;
    }
};
