class Solution {
public:
    int countSquares( vector<vector<int>>& matrix ) {
        int result = 0;
        int nbRow = matrix.size();
        int nbCol = matrix[0].size();
        
        for ( int row = 0; row < nbRow; row++ ) {
            for ( int col = 0; col < nbCol; col++ ) {
                if ( matrix[row][col] == 1 ) {
                    if ( row == 0 || col == 0 )
                        result++;
                    else {
                        int cell_val = 
                            getMin( matrix[row-1][col-1], matrix[row][col-1], matrix[row-1][col] ) + matrix[row][col];
                        result += cell_val;
                        matrix[row][col] = cell_val;
                    }
                }
            }
        }
        
        return result;
    }
    
    int getMin( int a, int b, int c ) {
        if ( a > b )
            return min( b, c );
        else
            return min( a, c );
    }
};
