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
        ListNode *p = head;
        int c = 0;
        while(p!=NULL){
            p = p->next;
            c++;
        }
        if(n==c){
            p = head;
            head = p->next;
            return head;
        }
        else{
            p = head;
            ListNode* q = head->next;
            int i = c-n-1;
            while(i>0){
                p = p->next;
                q = q->next;
                i--;
            }
            p->next = q->next;
        }
        return head;
    }
};