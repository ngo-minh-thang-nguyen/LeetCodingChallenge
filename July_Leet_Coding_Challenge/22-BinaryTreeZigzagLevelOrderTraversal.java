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
    public List<List<Integer>> zigzagLevelOrder( TreeNode root ) {
        if ( root == null )
            return new ArrayList<List<Integer>>();
        else {
            List<List<Integer>> result = new ArrayList<List<Integer>>();
            List<TreeNode> aNodeLine = new ArrayList<>();
            aNodeLine.add( root );
            boolean reverse = true;

            while ( !aNodeLine.isEmpty() ) {
                List<Integer> aLine = new ArrayList<Integer>();
                List<TreeNode> nextLine = new ArrayList<>();
                reverse = !reverse;
                // System.out.println(reverse);
                
                for ( TreeNode node : aNodeLine ) {
                    if ( node.left != null )
                        nextLine.add( node.left );
                    if ( node.right != null )
                        nextLine.add( node.right );
                }

                if ( !reverse ) {
                    for ( TreeNode node : aNodeLine ) {
                        aLine.add( node.val );
                    }
                }
                else {
                    for ( int i = aNodeLine.size() - 1; i >= 0; i -- ) {
                        aLine.add( aNodeLine.get(i).val );
                    }
                }
                
                aNodeLine = new ArrayList<>();

                for ( TreeNode aNo : nextLine ) {
                    aNodeLine.add( aNo );
                }

                result.add( aLine );
            }

            return result;
        }
    }
}
