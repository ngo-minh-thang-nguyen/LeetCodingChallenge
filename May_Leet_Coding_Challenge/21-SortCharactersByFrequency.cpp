class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mapCharAndFrequency;
        
        for ( int i = 0; i < s.size(); i++ ) {
            mapCharAndFrequency[ s[i] ]++;
        }
        
        map<int, vector<char>, greater <int>> mapSortFrequencyAndChars;
        
        for ( auto & entry : mapCharAndFrequency ) {
            mapSortFrequencyAndChars[ entry.second ].push_back( entry.first );
        }
        
        string result;
        
        for ( auto & entry : mapSortFrequencyAndChars ) {
            for ( char aChar : entry.second ) {
                int frequency = entry.first;
                while ( frequency > 0 ) {
                    result += aChar;
                    
                    frequency--;
                }
            }
        }
        
        return result;
    }
};
