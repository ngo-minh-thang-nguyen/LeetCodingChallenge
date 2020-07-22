class Solution {
public:
    bool exist( vector<vector<char>>& board, string word ) {
        int nbRow = board.size();
        int nbCol = board[0].size();
        
        for ( int i = 0; i < nbRow; i++ )
            for (int j = 0; j < nbCol; j++ )
                if ( existWord(board, word, 0, i, j) )
                    return true;
        
        return false;
    }
    
    bool existWord( vector<vector<char>>& board, string word, int index, int row, int col ) {
        if ( index == word.size() )
            return true;
        
        if ( row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index] )  
            return false;
        
        char c = board[row][col];
        board[row][col] = '*';
        
        bool ret = existWord(board, word, index+1, row-1, col) || existWord(board, word, index+1, row+1, col) || 
            existWord(board, word, index+1, row, col-1) || existWord(board, word, index+1, row, col+1); 
        board[row][col] = c;       
        
        return ret;
    }
};
