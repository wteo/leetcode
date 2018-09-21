 // author:wangtao
 // date  :2014.11.8

/*********************************************************************************
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
        ListNode *prehead = new ListNode(0);
        prehead->next = head;
        
        ListNode* p1 = prehead,*p2 = head;
        
        while(p2->next){
            if(p2->val == p2->next->val){
                p2 = p2->next;
            }
            else{
                if(p1->next == p2)
                    p1 = p2;
                else
                    p1->next = p2->next;
                p2 = p2->next;
            }//else
            if(!p2->next)
                if(p1->next!=p2)
                    p1->next = nullptr;
        }//while
        return prehead->next;
    }
};