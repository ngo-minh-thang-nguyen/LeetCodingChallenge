class Solution {
public:
    
    string removeKdigits(string num, int k) {
        while ( k > 0 ) {
            findSmallest( num );
            k--;
        }
        return num;
    }
    
    string findSmallest( string& num ) {
        if ( num.size() <= 1 )
            num = "0";
        else {
            if ( num[1] == '0' ) {
                if ( num.size() > 2 ){
                    for ( int i = 1; i < num.size(); i++ ) {
                        if ( num[i] != '0' ) {
                            num = num.substr( i, num.size() - i );
                            break;
                        }
                        
                        if ( i == num.size() - 1 ) {
                            num = "0";
                            break;
                        }
                    }
                }
                else 
                    num = "0";
            }
            else {
                bool finDigit = false;
                for ( int i = 0; i < num.size() - 1; i++ ) {
                    if ( ( (int) num[i] ) > ( (int) num[i+1] ) ) {
                        num = num.substr( 0, i ) + num.substr( i+1, num.size() - (i+1) );
                        finDigit = true;
                        break;
                    }
                }
                if ( !finDigit )
                    num = num.substr( 0, num.size() - 1 );
            }
        }
        
        return num;
    }
};
