class Solution {
public:
    vector<vector<int>> floodFill( vector<vector<int>>& image, int sr, int sc, int newColor ) {
        // set of pairs to store all coordinates of flood pill pixels
        set<pair<int, int>> ourSet;
        
        // add first pair as (sr, sc) to our Set
        pair <int, int> firstPair; 
        firstPair.first = sr;
        firstPair.second = sc;
        ourSet.insert( firstPair );
        
        // get all coordinates of flood fill pixels in vector image
        getCoordinates( image, sr, sc, ourSet, image[sr][sc] );
        
        return changeToNewColor( image, ourSet, newColor );
    }
    
    // function gets all coordinates of flood fill pixels
    void getCoordinates( vector<vector<int>>& image, int row, int col, set<pair<int, int>>& ourSet, int initialPixel ) {
        
        // if one of these following conditions are satisfied:
        // 1. index out of column
        // 2. index out of row
        // 2. pixel at (row, col) is not initialPixel
        if ( row < 0 || row >= image.size() || col < 0 || col >= image[row].size() || image[row][col] != initialPixel )
            return;
        else {
            pair <int, int> aPair; 
            aPair.first = row;
            aPair.second = col;
            ourSet.insert( aPair );
        }
        
        pair <int, int> aPair; 
        
        aPair.first = row-1;
        aPair.second = col;
        if ( ourSet.find( aPair ) == ourSet.end() )
            getCoordinates( image, row-1, col, ourSet, initialPixel );
        
        aPair.first = row;
        aPair.second = col-1;
        if ( ourSet.find( aPair ) == ourSet.end() )
            getCoordinates( image, row, col-1, ourSet, initialPixel );
        
        aPair.first = row+1;
        aPair.second = col;
        if ( ourSet.find( aPair ) == ourSet.end() )
            getCoordinates( image, row+1, col, ourSet, initialPixel );
        
        aPair.first = row;
        aPair.second = col+1;
        if ( ourSet.find( aPair ) == ourSet.end() )
            getCoordinates( image, row, col+1, ourSet, initialPixel );
    }
    
    // function changes value of flood pixels to newColor
    vector<vector<int>> changeToNewColor( vector<vector<int>>& image, set<pair<int, int>>& ourSet, int newColor ) {
        for ( auto & entry : ourSet ) {
            image[ entry.first ][ entry.second ] = newColor;
        }
        
        return image;
    }
};
