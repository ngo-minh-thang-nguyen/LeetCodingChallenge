class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        
        for ( int i = 0; i < A.size(); i++ ) {
            for ( int j = 0; j < B.size(); j++ ) {
                if ( A[i][1] >= B[j][0] && A[i][1] <= B[j][1] ) {
                    vector<int> aVect;
                    aVect.push_back( max( A[i][0], B[j][0] ) );
                    aVect.push_back( A[i][1] );
                    result.push_back( aVect );
                }
                else if ( B[j][1] >= A[i][0] && B[j][1] <= A[i][1] ) {
                    vector<int> aVect;
                    aVect.push_back( max( A[i][0], B[j][0] ) );
                    aVect.push_back( B[j][1] );
                    result.push_back( aVect );
                }
            }
        }
        
        return result;
    }
};
