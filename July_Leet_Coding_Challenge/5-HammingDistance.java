class Solution {
    public int hammingDistance(int x, int y) {
        int result = x^y;
        
        // System.out.println( result );
        
        return countSetBits( result );
    }
    
    public int countSetBits(int n) { 
        int count = 0; 
        while ( n > 0 ) {
            System.out.println( "n: " + n ); 
            // System.out.println( "count BF: " + count ); 
            count += (n & 1); 
            // System.out.println( "count FT: " + count ); 
            n = n >> 1;
        } 
        return count; 
    }
}
