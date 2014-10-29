 // author:wangtao
 // date  :2014.10.28

/***********************************************************************************
* Reverse a linked list from position m to n. Do it in-place and in one-pass.

* For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*
  return 1->4->3->2->5->NULL.
*
  Note:
* Given m, n satisfy the following condition:
  1 ¡Ü m ¡Ü n ¡Ü length of list.
*
***********************************************************************************/

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n) return head;
        
        ListNode * p1 = new ListNode(0),*p2 ,*p;
        p = p1;
        p1->next = head;
        for(int i = 1;i < m;i++)
            p1 = p1->next;
        p2 = p1->next ;
        for(int i = 1;i<=n-m;i++){
            ListNode * p3=p2->next ;
            p2->next = p3->next;
            p3->next = p1->next;
            p1->next = p3;
            p3 = p2->next;
        }
        return p->next;
    }
};
