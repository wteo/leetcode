 // author:wangtao
 // date  :2014.11.8

/*********************************************************************************
* Given a sorted linked list, delete all duplicates such that each 
* element appear only once.
*
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
**********************************************************************************/
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return nullptr;
        ListNode *p1 = head,*p2 = head->next;
        while(p2){
            if(p1->val!=p2->val){
                p1->next = p2;
                p1 = p2;
            }
            p2 = p2->next;
            if(!p2) p1->next = nullptr;
        }
        return head;
    }
};
