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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if(k == 1) return head;
        int l = 0;
        ListNode *t = head;
        while(t != NULL){
            t = t->next;
            l++;
        }
        t = head;
        int m = k*(l/k);
        while(m--) t = t->next;
        // cout<<t->val<<endl;
        ListNode *q = head, *r = head;
        for(int i=0;i<l/k;i++){
            int h = 2*k - 1;
            ListNode *p = q;
            while(h-- && p != NULL) p = p->next;
            h = k;
            while(h--){
                r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            if(i == 0) head = p;
        }
        ListNode* rest = head;
        while(rest->next != NULL) rest = rest->next;
        rest->next = t;
        return head;
    }
};