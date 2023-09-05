/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        int i = 0;
        unordered_map<Node*, int> m;
        unordered_map<int, Node*> newM;

        Node *p = head;
        m[p] = i;

        Node* newHead = new Node(p->val);
        Node* q = newHead;
        newM[i++] = q;

        p = p->next;
        while(p!=NULL){
            m[p] = i;
            Node* temp = new Node(p->val);
            newM[i++] = temp;
            q->next = temp;
            q = q->next;
            p = p->next;
        }
        p = head;
        q = newHead;

        while(p != NULL && q != NULL){
            if(m.find(p->random) == m.end()){
                q->random = NULL;
                p = p->next;
                q = q->next;
            }
            else{
                int j = m[p->random];
                q->random = newM[j];
                p = p->next;
                q = q->next;
            }
        }

        return newHead;
    }
};