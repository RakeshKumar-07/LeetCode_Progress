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
    void deleteNode(ListNode* node) {
        ListNode* t = node->next;
        while(t->next != NULL){
            node->val = t->val;
            node = node->next;
            t = t->next;
        }
        node->val = t->val;
        node->next = NULL;
    }
};