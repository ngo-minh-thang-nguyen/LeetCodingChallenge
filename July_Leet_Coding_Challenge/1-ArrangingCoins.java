class Solution {
    public int arrangeCoins(int n) {        
        long row = (long) ( Math.sqrt( (long) 2 * n ) );
        
        while ( row * (row + 1) / 2 > n ) {
            row--;
        }
        
        return (int) row;
    }
}
