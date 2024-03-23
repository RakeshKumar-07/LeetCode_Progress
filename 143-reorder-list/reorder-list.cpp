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
    void reorderList(ListNode* head) {
        int l = 0;
        ListNode* t = head;
        while(t != NULL){
            t = t->next;
            l++;
        }
        l = (l+1)/2 - 1;
        t = head;
        while(l--) t = t->next;
        ListNode* h = t->next;
        
        ListNode *p = NULL, *q = h, *r = h;
        while(q != NULL){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        h = p;

        t->next = NULL;
        t = head;
        
        while(h != NULL && t != NULL){
            ListNode* p = t, *q = h;
            h = h->next;
            t = t->next;
            p->next = q;
            q->next = t;
        }
    }
};