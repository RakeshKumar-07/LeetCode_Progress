/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL) return {};

        stack<Node*> s;
        s.push(root);
        map<Node*, bool> m;
        m[NULL] = true;

        vector<int> ans;

        while(s.size() > 0){
            Node* t = s.top();

            reverse(t->children.begin(), t->children.end());

            for(int i=0;i<t->children.size();i++){
                if(t->children[i] != NULL && !m[t->children[i]]) s.push(t->children[i]);
            }
            
            bool vis = true;
            for(int i=0;i<t->children.size();i++) vis &= m[t->children[i]];
            
            if(vis){
                ans.push_back(t->val);
                m[t] = true;
                s.pop();
            }
        }
        return ans;
    }
};