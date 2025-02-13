/**
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

 * 
 * 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head ==0)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        if(even == 0)
            return odd;
        
        ListNode* o = odd;
        ListNode* e = even;
        
        while(o->next!=0 && e->next!=0){
            if(e->next!=0){
                o->next = e->next;
                o = o->next;
            }
            if(o!=0){
                e->next = o->next;
                e = e->next;
            }
        }
            o->next = even;
            return odd;
    }
};