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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* p = head;
        int i = 1;
        while(p!=NULL){
            if(i == left){
                while(i<=right){
                    v.push_back(p->val);
                    p = p->next;
                    i++;
                }
            }
            else{
                p = p->next;
                i++;
            }
        }
        i = 1;
        int j = 0;
        p = head;
        reverse(v.begin(), v.end());
        while(p!=NULL){
            if(i == left){
                while(i<=right){
                    p->val = v[j];
                    p = p->next;
                    i++;
                    j++;
                }
            }
            else{
                p = p->next;
                i++;
            }
        }
        return head;
    }
};