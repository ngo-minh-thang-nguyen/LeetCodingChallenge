class Solution {
    public int[] prisonAfterNDays( int[] cells, int N ) {
        int[] oldCell = new int[cells.length];
        int residu = N % 14;
        
        if ( residu == 0 ) {
            residu = 14;
            while ( residu > 0 ) {
                System.arraycopy( cells, 0, oldCell, 0, cells.length);

                for ( int i = 1; i < oldCell.length - 1; i++ ) {
                    if ( oldCell[i-1] == oldCell[i+1] )
                        cells[i] = 1;
                    else
                        cells[i] = 0;
                }
                cells[0] = 0;
                cells[cells.length - 1] = 0;
                residu--;
            }
        }
        else {
            while ( residu > 0 ) {
                System.arraycopy( cells, 0, oldCell, 0, cells.length);

                for ( int i = 1; i < oldCell.length - 1; i++ ) {
                    if ( oldCell[i-1] == oldCell[i+1] )
                        cells[i] = 1;
                    else
                        cells[i] = 0;
                }
                cells[0] = 0;
                cells[cells.length - 1] = 0;
                residu--;
            }
        }
        
        return cells;
    }
}
