class Solution {
public:
    vector<int> countBits( int num ) {
        vector<int> res;
        
        if ( num == 0 )
            res.push_back(0);
        else if ( num == 1 )
            res = {0, 1};
        else {
            res.push_back( 0 );
            res.push_back( 1 );

            int idx = 0;

            while ( res.size() <= num ) {
                vector<int> aRange( &res[ (int) pow( 2, idx ) ], &res[ (int) pow( 2, idx + 1 ) ] );

                res.reserve( res.size() + aRange.size() ); // preallocate memory
                res.insert( res.end(), aRange.begin(), aRange.end() );

                std::for_each( aRange.begin(), aRange.end(), [](int& d) { d += 1;} );

                res.reserve( res.size() + aRange.size() ); // preallocate memory
                res.insert( res.end(), aRange.begin(), aRange.end() );

                idx++;
            }

            while ( res.size() > num + 1 ) {
                res.pop_back();
            }
        }
        
        return res;
    }
};
