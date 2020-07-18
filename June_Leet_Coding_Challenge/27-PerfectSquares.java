class Solution {
    public int numSquares(int n) {
        
        int result = n, num = 2;
        while ( num*num<=n ) {
            int temp1 = n / ( num*num ), temp2 = n%( num*num );
            result= Math.min( result, temp1 + numSquares(temp2) );
            num++;
        }
        
        return result;
    }
}
