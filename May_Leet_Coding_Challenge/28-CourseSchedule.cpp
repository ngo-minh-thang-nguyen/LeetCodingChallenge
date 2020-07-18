class Solution {
public:
    bool canFinish( int numCourses, vector<vector<int>>& prerequisites ) {
        if ( prerequisites.size() == 0 ) {
            return true;
        }
        
        vector<vector<int>> courses(numCourses);
        
        for ( auto i : prerequisites ) {
            courses[ i[1] ].push_back( i[0] );
        }
        
        vector<int> visited( numCourses, 0 );
        
        for ( int i = 0; i < numCourses; i++ ) {
            if ( !dfsUtil( i, courses, visited ) ) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfsUtil( int nb, vector<vector<int>>& courses, vector<int>& visited ) {
        visited[nb] = 1;
        
        for ( auto next : courses[nb] ) {
            if ( visited[next] == 1 || ( visited[next] == 0 && !dfsUtil( next, courses, visited ) ) ) {
                return false;
            }
        }
        
        visited[nb] = 0;
        
        return true;
    }
};
