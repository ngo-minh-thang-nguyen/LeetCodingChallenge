class Solution {
public:
    int findComplement( int num ) {
        string binaryResult;
        
        // find binary representation of num
        decimalToBinary( num, binaryResult );
        
        // find complement binary of binaryResult
        for ( int i = 0; i < binaryResult.size(); i++ ) {
            if ( binaryResult[i] == '0' ) binaryResult[i] = '1';
            else binaryResult[i] = '0';
        }
        
        return stoi( binaryResult, 0, 2 );
    }
    
    void decimalToBinary( int n, string& result ) 
    {
        // if n is more than 1, we divide it by two
        if (n > 1)
            decimalToBinary( n/2, result );

        // until n is equal to 1, than we print the result
        result += to_string( n % 2 );
    }
};
