class Solution {
public:
    vector<int> largestDivisibleSubset( vector<int>& nums ) {
        vector<int> res;        
        int n = nums.size();
        
        if ( n==0 )
            return res;
        sort(nums.begin(), nums.end());
        vector<int> div( n,1 );      
        vector<int> prev( n,-1 );
        
        int max_idx = 0;
        
        for ( int i = 1; i < n; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                if ( nums[i] % nums[j] == 0 ) {
                    if ( div[i] < div[j]+1 ) {
                        div[i] = div[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if ( div[max_idx] < div[i] )
                max_idx = i;
        }
        
        while ( max_idx >= 0 ) {
            res.push_back( nums[max_idx] );
            max_idx = prev[max_idx];
        }
        
        reverse( res.begin(), res.end() );
        return res;
    }
};
