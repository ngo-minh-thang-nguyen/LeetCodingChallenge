class Solution {
public:
    string getPermutation( int n, int k ) {
        int fact = getFactorial( n-1 ), insert;
        vector<int> remain( n, 1 );
        fillVectorOneToN( remain );
        string res = "";
        for ( int i = 0; i < n-1; i++ ) {
            insert = (k-1)/fact;
            res += '0' + remain[insert];
            remain.erase( remain.begin() + insert );
            k = (k-1) % fact + 1;
            fact /= n - i - 1;
        }
        res += '0' + remain[0];
        return res;
    }
    
    int getFactorial(int n){
        int ans = 1, i = 1;
        
        while ( i <= n ) {
            ans *= i++;
        }
        
        return ans;
    }
    
    void fillVectorOneToN(vector<int>& aVect){
        for ( int i = 0; i < aVect.size(); i++ ) {
            aVect[i] = i + 1;
        }
    }
    
//     string getPermutation( int n, int k ) {
//         string result;
//         int facto = n - 1;
        
//         int digit = 1;
//         while ( k > getFactoriel( facto ) ) {
//             result += (char)digit;
//             cout << "digit : " << digit << endl;
//             digit++;
            
//             facto--;
//             k = k - getFactoriel( facto );
            
//             if ( k == 0 ) {
//                 result += (char)digit;
//                 cout << "digit inside : " << digit << endl;
//                 digit = 1;
//                 facto--;
//             }
//         }
        
//         if ( k == 0 )
        
//         return result;
//     }
    
//     int getFactoriel( int idx ) {
//         int res = 1;
        
//         for ( int i = 1; i <= idx; i++ )
//             res = res * i;
        
//         return res;
//     }
};
