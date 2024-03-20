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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int A = a-1, B = b+1, diff = B - A;
        ListNode *t1 = list1, *t2 = list1;
        while(diff--) t2 = t2->next;
        while(A--){
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = list2;
        ListNode* l = list2;
        while(l->next != NULL) l = l->next;
        l->next = t2;
        return list1;
    }
};