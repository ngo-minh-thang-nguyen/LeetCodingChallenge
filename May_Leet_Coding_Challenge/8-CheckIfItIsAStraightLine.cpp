class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // coordinate of first point
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        
        // coordinate of second point
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        
        // a straight line is represented by the following equation:
        // y = a*x+b
        // We suppose that this line goes through first point, then we have: y1 = a*x1+b
        // Similarly, we have: y2 = a*x2+b. Our goal is to find coefficients a and b
        if ( x2 != x1 ) {
            double a = ( y2 - y1 ) / ( x2 - x1 );
            double b = y1 - a * x1;
            
            for ( int i = 1; i < coordinates.size(); i++ ) {
                if ( coordinates[i][1] != a*coordinates[i][0] + b )
                    return false;
            }
        }
        else {
            for ( int i = 1; i < coordinates.size(); i++ ) {
                if ( coordinates[i][0] != x1 )
                    return false;
            }
        }
        return true;
    }
};
