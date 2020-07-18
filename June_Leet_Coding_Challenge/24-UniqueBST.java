class Solution {
    public int numTrees(int n) {
        int [] table_DP = new int[n+1];
        table_DP[0] = table_DP[1] = 1;

        for ( int i = 2; i <= n; i++ ) {
            for ( int j = 1; j <= i; j++ ) {
                table_DP[i] += table_DP[j-1] * table_DP[i-j];
            }
        }
        
        return table_DP[n];
    }
}
