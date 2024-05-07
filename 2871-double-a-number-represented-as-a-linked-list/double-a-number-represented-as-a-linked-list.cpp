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
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        ListNode *p = head;
        v.push_back(0);
        while(p != NULL){
            v.push_back(p->val);
            p = p->next;
        }
        int r = 0;
        for(int i=v.size()-1;i>=0;i--){
            int t = 2*v[i] + r;
            v[i] = t%10;
            r = t/10;
        }
        int i = 0;
        while(i < v.size()){
            ListNode *q = new ListNode(v[i]);
            if(i == 0){
                p = q;
                head = p;
            }
            else{
                p->next = q;
                p = p->next;
            }
            i++;
        }
        return head->val == 0 ? head->next : head;
    }
};