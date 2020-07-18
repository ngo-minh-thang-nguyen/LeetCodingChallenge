class Solution {
public:
    int findCheapestPrice( int n, vector<vector<int>>& flights, int src, int dst, int K ) {
        unordered_map<int, vector<pair<int,int>>> ourMap;
        
        for ( const auto & conn : flights ) {
            pair <int, int> aPair;
            aPair.first = conn[1];
            aPair.second = conn[2];
            ourMap[ conn[0] ].push_back( aPair );
        }
        
        int res = INT_MAX;
        vector<int> visited( n, 0 );
        dfs( src, dst, K + 1, 0, visited, res, ourMap );
        return res == INT_MAX ? - 1 : res;
    }
    
    void dfs( int src, int dst, int k, int cost, vector<int>& visited, int& res, unordered_map<int, vector<pair<int,int>>>& ourMap ) {
        if ( src == dst ) {
            res = cost;
            return;
        }
        
        if ( k == 0 )
            return;
        
        visited[src] = 1;
        
        for ( auto & pair : ourMap[src] ) {
            if ( visited[ pair.first ] == 0 ) { // if not visited
                if ( cost + pair.second > res ) continue;

                dfs( pair.first, dst, k - 1, cost + pair.second, visited, res, ourMap ); 
            }
        }
        
        visited[src] = 0;
    }
    
//     void findRoute( vector<vector<int>>& flights, int src, int dst, int& nbStops, int K, int actualPrice, int& cheapest ) {
//         if ( src == dst ) {
//             if ( actualPrice < cheapest )
//                 cheapest = actualPrice;
//             return;
//         }
        
//         cout << "nbStops out : " << nbStops << endl;
//         if ( nbStops > K ) {
//             cheapest = 0;
//             cout << "nbStops in : " << nbStops << endl;
//             return;
//         }
        
//         for ( auto & aConnection : flights ) {
//             if ( aConnection[0] == src ) {
//                 cout << "src : " << src << endl;
//                 actualPrice += aConnection[2];
//                 cout << "actualPrice : " << actualPrice << endl;
//                 cout << "-----------------------" << endl;
//                 nbStops = nbStops + 1;
//                 findRoute( flights, aConnection[1], dst, nbStops, K, actualPrice, cheapest );
//             }
//         }
        
//     }
};
