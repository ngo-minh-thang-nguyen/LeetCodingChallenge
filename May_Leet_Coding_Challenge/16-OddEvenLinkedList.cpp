/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if ( !head ) return NULL;
        
        ListNode * odd=head;
        ListNode * evenHead = head->next, *even = evenHead;
        
        while ( even && even->next ) {
            odd->next = odd->next->next;
            
            if ( even->next->next ) {
                even->next = even->next->next;

                even = even->next;
            }
            else
                even->next = NULL;
            
            odd = odd->next;
        }
        
        odd->next = evenHead;
        
        return head;
    }
};
