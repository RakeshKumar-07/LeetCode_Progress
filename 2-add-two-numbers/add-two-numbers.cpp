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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, c = -1;
        ListNode *t1 = l1, *t2 = l2;
        ListNode *p1 = l1, *p2 = l2;
        while(t1 != NULL && t2 != NULL){
            sum += t1->val + t2->val;
            t1->val = sum%10;
            t2->val = sum%10;
            sum /= 10;
            p1 = t1;
            p2 = t2;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1 != NULL){
            c = 1;
            sum += t1->val;
            t1->val = sum%10;
            sum /= 10;
            p1 = t1;
            t1 = t1->next;
        }
        while(t2 != NULL){
            c = 0;
            sum += t2->val;
            t2->val = sum%10;
            sum /= 10;
            p2 = t2;
            t2 = t2->next;
        }
        while(sum > 0){
            ListNode *t = new ListNode(sum%10);
            p1->next = t;
            p2->next = t;
            p1 = p1->next;
            p2 = p2->next;
            sum /= 10;
        }
        // cout<<c<<endl;
        return c == 1 ? l1 : l2;
    }
};