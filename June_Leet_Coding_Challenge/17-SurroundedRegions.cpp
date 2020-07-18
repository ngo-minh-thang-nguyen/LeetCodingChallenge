class Solution {
public:
    void solve( vector<vector<char>>& board ) {
        for ( int row = 0; row < board.size(); row++ ) {
            for ( int col = 0; col < board[0].size(); col++ ) {
                vector< pair<int, int> > coordinates;
                bool modify = true;
                if ( board[row][col] == 'O' ) {
                    doFlip( board, row, col, coordinates, modify );
                }
                
                if ( coordinates.size() > 0 ) {
                    if ( modify ) {
                        for ( const pair<int, int> & aCoordinate : coordinates ) {
                            board[aCoordinate.first][aCoordinate.second] = 'X';
                        }
                    }
                    else {
                        for ( const pair<int, int> & aCoordinate : coordinates ) {
                            board[aCoordinate.first][aCoordinate.second] = 'O';
                        }
                    }
                }
            }
        }
    }
    
    void doFlip( vector<vector<char>>& board, int row, int col, vector< pair<int, int> >& coordinates, bool& modify ) {
        if ( 0 == row || board.size() - 1 == row || 0 == col || board[0].size() - 1 == col ) {
            if ( board[row][col] == 'O' ) {
                modify = false;
                return;
            }
        }
        
        if ( board[row][col] == 'O' ) {
            // cout << "row : " << row << endl;
            // cout << "col : " << col << endl;
            coordinates.push_back( make_pair( row, col ) );
        }
        
        board[row][col] = 'V';
        
        if ( 0 <= row - 1 && board[row - 1][col] == 'O' )
            doFlip( board, row - 1, col, coordinates, modify );
        if ( row + 1 < board.size()  && board[row + 1][col] == 'O' )
            doFlip( board, row + 1, col, coordinates, modify );
        if ( col - 1 >= 0  && board[row][col - 1] == 'O' )
            doFlip( board, row, col - 1, coordinates, modify );
        if ( col + 1 < board[0].size()  && board[row][col + 1] == 'O' )
            doFlip( board, row, col + 1, coordinates, modify );
    }
};
