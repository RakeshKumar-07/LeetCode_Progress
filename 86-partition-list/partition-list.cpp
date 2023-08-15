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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1, v2;
        ListNode* p = head;
        while(p!=NULL){
            if(p->val < x) v1.push_back(p->val);
            else v2.push_back(p->val);
            p = p->next;
        }
        
        p = head;
        int i = 0;
        while(i<v1.size()){
            p->val = v1[i++];
            p = p->next;
        }

        i = 0;
        while(i<v2.size()){
            p->val = v2[i++];
            p = p->next;
        }

        return head;
    }
};