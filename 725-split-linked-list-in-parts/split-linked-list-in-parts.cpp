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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        vector<int> len(k,0);
        int size = 0;
        ListNode* p = head;
        while(p!=NULL){
            p = p->next;
            size++;
        }
        int a = size/k, b = size%k;
        for(int i=0;i<k;i++){
            len[i] = a;
            if(b>0){
                len[i] += 1;
                b--;
            }
        }
        p = head;
        for(int i=0;i<k;i++){
            if(p!=NULL){
                ListNode *q = p->next;
                while(len[i]>1){
                    p = p->next;
                    q = q->next;
                    len[i]--;
                }
                p->next = NULL;
                ans.push_back(head);
                head = q;
                p = q;
            }
            else{
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};