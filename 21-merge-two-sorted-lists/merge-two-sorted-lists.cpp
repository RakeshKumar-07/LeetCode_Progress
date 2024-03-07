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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *h1 = list1, *h2 = list2, *t = NULL;
        while(h1 != NULL && h2 != NULL){
            // cout<<h1->val<<" -> "<<h2->val<<endl;
            if(h1->val <= h2->val){
                if(t == NULL){
                    t = h1;
                    h1 = h1->next;
                }
                else{
                    t->next = h1;
                    h1 = h1->next;
                    t = t->next;
                }
            }
            else{
                if(t == NULL){
                    t = h2;
                    h2 = h2->next;
                }
                else{
                    t->next = h2;
                    h2 = h2->next;
                    t = t->next;
                }
            }
        }
        if(h1 != NULL) t->next = h1;
        if(h2 != NULL) t->next = h2;
        return list1->val <= list2->val ? list1 : list2;
    }
};