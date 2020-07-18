class Solution {
    int maxHeight = 0;
    
    public List<List<Integer>> levelOrderBottom( TreeNode root ) {
        maxHeight = determineHeight( root, 0 );
        
        // System.out.println( maxHeight );
        
        List<List<Integer>> bottomUpOrder = new ArrayList<List<Integer>>();
        List<Integer> aListOfSameHeight;
        for ( int i = 0; i <= maxHeight; i++ ) {
            aListOfSameHeight = new ArrayList<Integer>();
            bottomUpOrder.add( i, aListOfSameHeight );
        }
        
        constructOrder( root, 0, bottomUpOrder );
        
        return bottomUpOrder;
    }
    
    public void constructOrder( TreeNode aNode, int height, List<List<Integer>> bottomUpOrder ) {
        if ( aNode == null )
            return;
        
        bottomUpOrder.get( maxHeight - height ).add( aNode.val );
        
        // System.out.println( "aNode.val : " + aNode.val );
        // System.out.println( "maxHeight OUT : " + maxHeight );
        
        constructOrder( aNode.left, height + 1, bottomUpOrder );
        constructOrder( aNode.right, height + 1, bottomUpOrder );
    }
    
    public int determineHeight( TreeNode aNode, int maxHeight ) {
        if ( aNode == null ) {
            return maxHeight - 1;
        }
        
        return Math.max( determineHeight( aNode.left, maxHeight + 1 ), 
                        determineHeight( aNode.right, maxHeight + 1 ) );
    }
}
