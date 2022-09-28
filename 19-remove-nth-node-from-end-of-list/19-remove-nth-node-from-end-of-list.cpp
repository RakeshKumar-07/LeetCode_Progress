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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while(n>0){
            q = q->next;
            n--;
        }
        if(q == NULL){
            head = head->next;
            return head;
        }
        else{
            while(q->next != NULL){
                p = p->next;
                q = q->next;
            }
            if(p->next == q){
                p->next = p->next->next;
                return head;
            }
            p->next = p->next->next;
            return head;
        }
        // if(n==c){
        //     p = head;
        //     head = p->next;
        //     return head;
        // }
        // else{
        //     p = head;
        //     ListNode* q = head->next;
        //     int i = c-n-1;
        //     while(i>0){
        //         p = p->next;
        //         q = q->next;
        //         i--;
        //     }
        //     p->next = q->next;
        // }
        return head;
    }
};