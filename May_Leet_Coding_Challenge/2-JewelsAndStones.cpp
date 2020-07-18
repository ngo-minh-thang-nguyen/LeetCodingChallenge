class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // variable stores result
        int numberOfJewels = 0;
        
        // create map between each type of jewel and its frequency in string S
        map<char, int> mapJewelAndFrequency;
        
        // add all types of jewel to map
        for ( int i=0; i<J.size(); i++ ) {
            mapJewelAndFrequency[ J[i] ] = 0;
        }
        
        // look for all types of jewels in string S and store in the map
        for ( int i=0; i<S.size(); i++ ) {
            if ( mapJewelAndFrequency.find( S[i] ) != mapJewelAndFrequency.end() )
                mapJewelAndFrequency[ S[i] ]++;
        }
        
        // count number of jewels in map
        for ( auto & anEntry : mapJewelAndFrequency ) {
            numberOfJewels += mapJewelAndFrequency[ anEntry.first ];
        }
        
        return numberOfJewels;
    }
};
