 // author:wangtao
 // date  :2014.10.28

/****************************************************************************************************************
*  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order 
*  and each of their nodes contain a single digit.
*  Add the two numbers and return it as a linked list.
*
*  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*  Output: 7 -> 0 -> 8
*
*****************************************************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        ListNode head(-1);
        ListNode * ptr = &head;
        int carry = 0;
        
        while (l1 && l2){
            ptr->next = new ListNode( (carry +l1->val+l2->val)%10);
            carry = (carry +l1->val+l2->val)/10;
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode * pptr = (l1?l1:l2);
        
        while(pptr){
            ptr->next = new ListNode((carry +pptr->val)%10);
            carry = (carry +pptr->val)/10;
            ptr = ptr->next;
            pptr = pptr->next;
        }
        
        if(carry == 1){
            ptr->next = new ListNode(1);
        }
        return head.next;
    }
};
