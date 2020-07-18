class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int size1 = A.size();
        int size2 = B.size();
        
        int dp[ size1 + 1 ][ size2 + 1 ];
        
        for ( int i = 0; i <= size1; i++ ) {
            dp[i][0] = 0;
        }
        
        for ( int j = 0; j <= size2; j++ ) {
            dp[0][j] = 0;
        }
        
        for ( int i = 1; i <= size1; i++ ) {
            for ( int j = 1; j <= size2; j++ ) {
                if ( A[i - 1] == B[j - 1] ) {
                    dp[i][j]  = dp[i - 1][j - 1] + 1;
                } 
                else {
                    dp[i][j] = max( dp[i - 1][j - 1], 
                                   max( dp[i - 1][j], dp[i][j - 1] ) );
                }
            }
        }
        
        // for ( int i = 0; i <= size1; i++ ) {
        //     for ( int j = 0; j <= size2; j++ ) {
        //         cout << "i : "<< i << " and j : " << j << " and : " << dp[i][j] << endl;
        //     }
        // }
        
        return dp[size1][size2];
    }
};
