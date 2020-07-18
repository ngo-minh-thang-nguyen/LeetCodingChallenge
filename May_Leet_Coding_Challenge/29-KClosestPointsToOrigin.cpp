class Solution {
public:
    vector<vector<int>> kClosest( vector<vector<int>>& points, int K ) {
        map< float, vector<vector<int>> > mapPointAndDistance;
        
        for ( vector<int> aPoint : points ) {
            mapPointAndDistance[ sqrt( aPoint[0] * aPoint[0] + aPoint[1] * aPoint[1] ) ].push_back( aPoint );
        }
        
        vector<vector<int>> res;
        int count = 0;
        
        for ( auto entry : mapPointAndDistance ) {
            if ( count < K ) {
                for ( vector<int> aVect : entry.second ) {
                    res.push_back( aVect );
                    count++;
                }
            }
            else
                break;
        }
        
        return res;
    }
};
