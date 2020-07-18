class Solution {
public:
    int maxSubarraySumCircular( vector<int>& A ) {
        if ( A.size() >= 2 ) {
            int maxSum1 = findMaxSum( A, 0, A.size() - 1 );

            int sum = 0;
            for ( int nb : A ) 
                sum += nb;

            int minSum1 = findMinSum( A, 0, A.size() - 2 );
            int minSum2 = findMinSum( A, 1, A.size() - 1 );
            int minSum = min( minSum1, minSum2 );
            
            int maxSum2 = sum - minSum;

            return max( maxSum1, maxSum2 );
        }
        else {
            return A[0];
        }
    }
    
    int findMaxSum( vector<int>& doubleVector, int left, int right ) {
        if ( left == right ) {
            return doubleVector[left];
        }
        else {
            int maxSum = INT_MIN;
            int dp[ right - left + 1 ];

            dp[0] = doubleVector[left];

            for ( int i = left+1; i <= right; i++ ) {
                dp[i - left] = max( dp[i - left - 1], 0 ) + doubleVector[i];
                if ( dp[i - left] > maxSum )
                    maxSum = max( dp[i - left], maxSum );
            }

            return maxSum;
        }
    }
    
    int findMinSum( vector<int>& doubleVector, int left, int right ) {
        if ( left == right ) {
            return doubleVector[left];
        }
        else {
            int minSum = INT_MAX;
            int dp[ right - left + 1 ];

            dp[0] = doubleVector[left];

            for ( int i = left+1; i <= right; i++ ) {
                dp[i - left] = min( dp[i - left - 1], 0 ) + doubleVector[i];
                if ( dp[i - left] < minSum )
                    minSum = min( dp[i - left], minSum );
            }

            return minSum;
        }
    }
};
