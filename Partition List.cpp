 // author:wangtao
 // date  :2014.11.09

/********************************************************************************************
* Given a linked list and a value x, partition it such that all nodes less than x 
* come before nodes greater than or equal to x.
*
* You should preserve the original relative order of the nodes in each of the two partitions.
*
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
*********************************************************************************************/


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
    ListNode *partition(ListNode *head, int x) {
        ListNode *head1 = new ListNode(0);
        ListNode *head2 = new ListNode(0);
        ListNode *p1=head1,*p2=head2,*p=head;
        while(p){
            if(p->val < x){
                p1->next = p;
                p1 = p1->next;
            }else{
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }//while
        p2->next = nullptr;
        p1->next = head2->next;
        return head1->next;
    }
};