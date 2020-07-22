/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if ( head == null )
            return null;
        else {
            ListNode aNode = head;

            if ( aNode.next == null ) {
                if ( aNode.val == val )
                    return null;
                else
                    return head;
            }
            else {
                while ( aNode.next != null ) {
                    // System.out.println( "aNode.val : " + aNode.val );
                    if ( aNode.next.val == val ) {
                        if ( aNode.next.next != null )
                            aNode.next = aNode.next.next;
                        else
                            aNode.next = null;
                    }

                    if ( aNode.next != null ) {
                        if ( aNode.next.val != val )
                            aNode = aNode.next;
                    }
                }
                
                if ( head.val == val ) {
                    if ( head.next == null )
                        return null;
                    else
                        return head.next;
                }
                else
                    return head;
            }
        }
    }
}
