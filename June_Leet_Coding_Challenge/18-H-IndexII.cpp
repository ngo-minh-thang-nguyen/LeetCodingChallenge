class Solution {
public:
    int hIndex( vector<int>& citations ) {
        if ( citations.size() == 0 )
            return 0;
        
        int res = 0;
        int right = citations.size();
        
        while ( 0 < right ) {
            if ( res >= citations[right - 1] )
                return res;
            
            if ( right - citations[right - 1] >= 0 ) {
                if ( citations[right - 1] == 0 )
                    return 0;
                
                if ( citations[ right - citations[right - 1] ] == citations[right - 1] ) {
                    return citations[right - 1];
                }
                else {
                    res++;
                    if ( res == citations[right - 1] )
                        return res;
                    right--;
                }
            }
            else {
                res++;
                right--;
            }
        }
        
        return res;
    }
    
//     int hIndex( vector<int>& citations ) {
//         int n = citations.size();
        
//         if ( !n ) return 0;
        
//         int low = 0;
//         int high = n - 1;
//         int ans = 0;
        
//         while ( low <= high ) {
//             int mid  = low + ( high - low ) / 2;
//             if ( citations[mid] >= n - mid ) {
//                 ans = n - mid;
//                 high = mid - 1;
//             }
//             else {
//                 low  = mid + 1;
//             }
//         }
        
//         return ans;
// 	}
};
