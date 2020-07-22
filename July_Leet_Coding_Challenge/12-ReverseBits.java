public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        String origString = Integer.toBinaryString(n);
        
        String revString = "";
        
        for ( int i = origString.length() - 1; i >= 0; i-- ) {
            revString += origString.charAt(i);
        }
        
        int lengthRev = revString.length();
        
        if ( lengthRev < 32 ) {
            for ( int j = 0; j < 32 - lengthRev; j++ )
                revString += "0";
        }
        
        return (int) Long.parseLong(revString, 2);
    }
}
