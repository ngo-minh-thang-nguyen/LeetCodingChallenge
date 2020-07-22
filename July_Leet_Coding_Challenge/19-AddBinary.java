class Solution {
    public String addBinary( String a, String b ) {
        int maxLength = Math.max( a.length(), b.length() );
        
        if ( b.length() < maxLength ) {
            String bInverse = "";
            for ( int i = b.length() - 1; i >= 0; i-- ) {
                bInverse += b.charAt(i);
            }
            for ( int i = b.length(); i < maxLength; i++ ) {
                bInverse += "0";
            }
            
            b = "";            
            for ( int i = maxLength - 1; i >= 0; i-- ) {
                b += bInverse.charAt(i);
            }
        }
        // System.out.println(a);
        
        if ( a.length() < maxLength ) {
            String aInverse = "";
            for ( int i = a.length() - 1; i >= 0; i-- ) {
                aInverse += a.charAt(i);
            }
            for ( int i = a.length(); i < maxLength; i++ ) {
                aInverse += "0";
            }
            
            a = "";
            for ( int i = maxLength - 1; i >= 0; i-- ) {
                a += aInverse.charAt(i);
            }
        }
        
        // System.out.println(b);
        String resultInverse = "";
        boolean remember = false;
        
        for ( int i = maxLength - 1; i >= 0; i-- ) {            
            if ( a.charAt(i) == '0' && b.charAt(i) == '0' ) {
                // resultInverse += "0";
                if ( !remember )
                    resultInverse += "0";
                else {
                    resultInverse += "1";
                    remember = false;
                }
            }
            else if ( a.charAt(i) == '1' && b.charAt(i) == '0' ) {
                if ( !remember )
                    resultInverse += "1";
                else {
                    resultInverse += "0";
                }
            }
            else if ( a.charAt(i) == '0' && b.charAt(i) == '1' ){
                if ( !remember )
                    resultInverse += "1";
                else {
                    resultInverse += "0";
                }
            }
            else {
                if ( !remember ) {
                    resultInverse += "0";
                    remember = true;
                }
                else {
                    resultInverse += "1";
                }
            }
        }
        
        if ( remember ) {
            resultInverse += "1";
        }
        
        String result = "";
        
        for ( int i = resultInverse.length() - 1; i >= 0; i-- ) {
            result += resultInverse.charAt(i);
        }
        
        return result;
    }
}
