class Solution {
    public int islandPerimeter(int[][] grid) {
        boolean found = false;
        int i = 0, j = 0;
        
        for ( i = 0; i < grid.length; i++ ) {
            for ( j = 0; j < grid[0].length; j++ ) {
                if ( grid[i][j] == 1 ) {
                    found = true;
                    break;
                }
            }
            if ( found )
                break;
        }
        
        int result = determinePerimeter( grid, i, j );
        
        return result;
    }
    
    public int determinePerimeter( int[][] grid, int i, int j ) {
        if ( i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != 1 )
            return 0;
        
        int surround = 0;
        if ( i-1 >= 0 ) {
            if ( grid[i-1][j] == 1 || grid[i-1][j] == 2 )
                surround++;
        }
        if ( i+1 < grid.length ) {
            if ( grid[i+1][j] == 1 || grid[i+1][j] == 2 )
                surround++;
        }
        if ( j-1 >= 0 ) {
            if ( grid[i][j-1] == 1 || grid[i][j-1] == 2 )
                surround++;
        }
        if ( j+1 < grid[0].length ) {
            if ( grid[i][j+1] == 1 || grid[i][j+1] == 2 )
                surround++;
        }
        
        // System.out.println( "i : " + i + " and j : " + j );
        // System.out.println( "4 - surround : " + String.valueOf(4 - surround) );
        
        grid[i][j] = 2;
        
        return (4 - surround) + determinePerimeter( grid, i - 1, j ) +
                determinePerimeter( grid, i, j - 1 ) +
                determinePerimeter( grid, i + 1, j ) +
                determinePerimeter( grid, i, j + 1 );
    }
}
