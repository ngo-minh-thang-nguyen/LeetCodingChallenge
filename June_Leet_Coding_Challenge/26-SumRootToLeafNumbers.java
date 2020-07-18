/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers( TreeNode root ) {
        String aNum = "";
        return sumAllPaths( root, aNum );
    }
    
    public int sumAllPaths( TreeNode aNode, String aNum ) {
        if ( aNode == null )
            return 0;
        
        if ( aNode.left == null && aNode.right == null ) {
            aNum += String.valueOf( aNode.val );
            return Integer.parseInt( aNum );
        }
        
        return sumAllPaths( aNode.left, aNum + String.valueOf( aNode.val ) ) + 
            sumAllPaths( aNode.right, aNum + String.valueOf( aNode.val ) );
    }
}
