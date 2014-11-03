  //Author:wangtao
  //Date  :2014.11.4
/******************************************************************************************************
*  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*  You may not alter the values in the nodes, only nodes itself may be changed.
*  Only constant memory is allowed.

*  For example,
*  Given this linked list: 1->2->3->4->5
*
*  For k = 2, you should return: 2->1->4->3->5
*  For k = 3, you should return: 3->2->1->4->5
*********************************************************************************************************/

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode * prehead = new ListNode(0);
        prehead->next = head;
        ListNode *p,*q,*r;
        r=prehead;
        p = head;
        while(p){
            int i=0;
            for(;i<k && p;i++){
                p=p->next;
            }
            
            if(i<k) return prehead->next;
            
            q=r->next;
            while(q->next!=p){
               ListNode *tmp = q->next;
               q->next = q->next->next;
               tmp->next = r->next;
               r->next = tmp;
            }
        
            r=q;
        }
       return prehead->next; 
    }
};