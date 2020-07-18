class Solution {
public:
    vector<vector<int>> reconstructQueue( vector<vector<int>>& people ) {
        map<int, set<int>> mapHeiAndK;
        
        for ( auto aPerson : people )
            mapHeiAndK[ aPerson[0] ].insert( aPerson[1] );
        
        vector<vector<int>> res( people.size() );
        vector<bool> visited( people.size(), false );
        
        for ( auto aPair : mapHeiAndK ) {
            int aHeight = aPair.first;
            vector<int> indexVisited;
            
            for ( int aK : aPair.second ) {
                vector<int> aVect;
                aVect.push_back( aHeight );
                aVect.push_back( aK );
                
                int i = 0;
                int ct = 0;
                while ( i < people.size() ) {
                    if ( !visited[ i ] )
                        ct++;
                    if ( ct > aK )
                        break;
                    i++;
                }
                
                res[ i ] = aVect;
                indexVisited.push_back( i );
            }
            
            for ( int idx : indexVisited ) {
                visited[ idx ] = true;
            }
        }
        
        return res;
    }
};
