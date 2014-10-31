  // author:wangtao
 // date  :2014.10.31

/****************************************************************************************************
* Given a linked list, swap every two adjacent nodes and return its head.

* For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.
*
  Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
****************************************************************************************************/

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

/*
//递归版本：
    ListNode *swapPairs(ListNode *head) {
        if(nullptr==head || nullptr==head->next)
            return head;
        ListNode * p = head;
        ListNode * q = head->next;
        ListNode * r = q->next;
        q->next = p;
        p->next = swapPairs(r);
        return q;
    }
*/

    ListNode *swapPairs(ListNode *head) {
        
        ListNode*prehead = new ListNode(0);
        prehead->next  = head; 
        ListNode * p = prehead;
        ListNode * q = head;
        while(q && q->next){
            ListNode * r = q->next;
            q->next = r->next;
            r->next = q;
            p->next = r;
            p=q;
            q=q->next;
        }
        return prehead->next;
    }
};