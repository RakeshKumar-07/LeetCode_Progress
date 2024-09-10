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
    int gcd(int a, int b){
        int result = min(a, b); 
        while (result > 0) { 
            if (a % result == 0 && b % result == 0) break;
            result--; 
        }
        return result; 
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head, *q = head;
        while(q->next != NULL){
            q = q->next;
            ListNode *t = new ListNode(gcd(p->val, q->val));
            p->next = t;
            t->next = q;
            p = q;
        }
        return head;
    }
};