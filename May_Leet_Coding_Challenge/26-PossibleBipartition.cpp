class Solution {
public:
    bool possibleBipartition( int N, vector<vector<int>>& dislikes ) {
        if ( N==1 ) 
            return true;
        
        unordered_map<int, set<int>> mapWithDislikes;

        for ( auto & aPair : dislikes ) {
            mapWithDislikes[ aPair[0] ].insert( aPair[1] );
            mapWithDislikes[ aPair[1] ].insert( aPair[0] );
        }

        // for ( auto & aPair : mapWithDislikes ) {
        //     cout << "aPair : " << aPair.first;
        //     for ( auto & nb : aPair.second ) {
        //         cout << " " << nb;
        //     }
        //     cout << endl;
        // }
        
        unordered_map<int, int> visited;

        for ( int i = 1; i <= N; i++ ) {
            if ( visited.count(i) == 1 ) {
                // cout << "i : " << i << " " << visited[i] << endl;
                continue;
            }
            
            // cout << "i : " << i << " " << visited[i] << endl;
            
            visited[i] = 1;

            deque<int> q;
            q.push_back(i); 

            while ( !q.empty() ) {
                auto curr = q.front();
                q.pop_front();

                for ( auto & nxt : mapWithDislikes[curr] ) {
                    if ( visited.count(nxt) == 1 && visited[nxt] == visited[curr] )
                        return false;
                    if ( visited.count(nxt) == 0 ) {
                        visited[nxt] = -visited[curr];
                        q.push_back(nxt);
                    }
                }
            }
        }
        
        return true;
    }
};

